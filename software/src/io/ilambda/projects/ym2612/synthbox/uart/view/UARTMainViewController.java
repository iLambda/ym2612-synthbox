package io.ilambda.projects.ym2612.synthbox.uart.view;

import jssc.*;

import java.io.*;
import io.ilambda.projects.ym2612.synthbox.uart.*;
import javafx.beans.binding.Bindings;
import javafx.beans.property.BooleanProperty;
import javafx.beans.property.ObjectProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleObjectProperty;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.*;	
import javafx.scene.control.*;
import javafx.scene.control.Alert.*;
import javafx.stage.*;
import javafx.stage.FileChooser.ExtensionFilter;

public class UARTMainViewController {
	
	@FXML
	private TextArea console;
	@FXML
	private TextField commandField;
	@FXML
	private Button sendButton;
	@FXML
	private Button connectButton;
	@FXML
	private CheckMenuItem autoconnectCheckBox;
	
	// File chooser
	private FileChooser fileChooser = new FileChooser(); 
	
	// Contains the port used by the program
	public static ObjectProperty<SerialPort> usedPort = new SimpleObjectProperty<SerialPort>(null);
	// Are we connected ?
	private BooleanProperty connected = new SimpleBooleanProperty(false);
	
	
	
	/**
     * Initializes the controller class. This method is automatically called
     * after the fxml file has been loaded.
     */
    @FXML
    private void initialize() {
        // Initialize the console
    	updatePort();       
    	
    	// Init file chooser
    	fileChooser.getExtensionFilters().add(new ExtensionFilter("Y12 Instrument File", "*.y12"));
    	fileChooser.getExtensionFilters().add(new ExtensionFilter("VGI Instrument File", "*.vgi"));
    	
    	// Bind stuff
    	commandField.disableProperty().bind(connected.not());
    	sendButton.disableProperty().bind(connected.not());
    	connectButton.disableProperty().bind(connected.not().or(Bindings.isNull(usedPort)));
    }
    
    /**
     * Open the list of COM ports
     */
    @FXML
    private void openCOMListDialog() {
		try {
			Stage dialog = new Stage();
			FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("UARTPortView.fxml"));
			dialog.setScene(new Scene(fxmlLoader.load()));
			UARTPortViewController controller = fxmlLoader.getController();
			controller.setParent(this);
			dialog.initOwner((Stage)console.getScene().getWindow());
			dialog.setTitle("Select a COM port");
			dialog.setResizable(false);
			dialog.initModality(Modality.APPLICATION_MODAL); 
			dialog.showAndWait();
		} catch (IOException e) {
			e.printStackTrace();
		}
    }
    
    /**
     * Export
     */
    @FXML
    private void exportInstrument() {
    	// choose file
    	fileChooser.setTitle("Export instrument to disk");
    	File fileChosen = fileChooser.showSaveDialog(console.getScene().getWindow());
    	
    	// if file chosen. else, dismiss
    	if (fileChosen != null) {
    		// open dialog
    		try {
    			Stage dialog = new Stage();
    			FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("UARTInstrumentChannelView.fxml"));
    			dialog.setScene(new Scene(fxmlLoader.load()));
    			UARTInstrumentChannelController controller = fxmlLoader.getController();
    			controller.setParent(this);
    			controller.setOperation(FileOperation.Export);
    			controller.setFile(fileChosen);
    			dialog.initOwner((Stage)console.getScene().getWindow());
    			dialog.setTitle("Choose channel");
    			dialog.setResizable(false);
    			dialog.initModality(Modality.APPLICATION_MODAL); 
    			dialog.showAndWait();
    		} catch (IOException e) {
    			e.printStackTrace();
    		}
    	}
    }
    
    /**
     * Import
     */
    @FXML
    private void importInstrument() {
    	// choose file
    	fileChooser.setTitle("Import instrument to device");
    	File fileChosen = fileChooser.showOpenDialog(console.getScene().getWindow());
    	
    	// if file chosen. else, dismiss
    	if (fileChosen != null) {
    		// open dialog
    		try {
    			Stage dialog = new Stage();
    			FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("UARTInstrumentChannelView.fxml"));
    			dialog.setScene(new Scene(fxmlLoader.load()));
    			UARTInstrumentChannelController controller = fxmlLoader.getController();
    			controller.setParent(this);
    			controller.setOperation(FileOperation.Import);
    			controller.setFile(fileChosen);
    			dialog.initOwner((Stage)console.getScene().getWindow());
    			dialog.setTitle("Choose channel");
    			dialog.setResizable(false);
    			dialog.initModality(Modality.APPLICATION_MODAL); 
    			dialog.showAndWait();
    		} catch (IOException e) {
    			e.printStackTrace();
    		}
    	}
    }
    
    /**
     * Update the text on the port
     */
    public void updatePort() {
    	if (usedPort.get() != null) {
    		// Port set.
    		console.setText("[Using COM port " + usedPort.get().getPortName() + "]\n");
    	} else {
    		// No port set.
    		console.setText("[No COM port " + (SerialPortList.getPortNames().length > 0 ? "set" : "found") + "]\n");
    	}
    }
    
    /**
     * Listen to port
     */
    public void listenPort() {
    	try {
        	// open
    		console.appendText("[Opening port " + usedPort.get().getPortName() + "..]\n");
    		if (!usedPort.get().isOpened()) {
            	usedPort.get().openPort();
    		}
    		console.appendText("[Port " + usedPort.get().getPortName() + " opened]\n");
    		
        	// listen to communication
    		console.appendText("[Hooking to port..]\n");
			usedPort.get().addEventListener(new COMPortListener());
    		console.appendText("[Hooked to port]\n");
		} catch (SerialPortException e) {
			// display error in console
			console.appendText("/!\\ ERROR : " + e.getExceptionType() + "\n");
			console.appendText("[Abort connection]");
			// display dialog
			Alert alert = new Alert(AlertType.ERROR);
			alert.setTitle("Error!");
			alert.setHeaderText("An error occured while hooking to port " + e.getPortName() + ".");
			alert.setContentText(e.getMessage());
			alert.showAndWait();
			// show connect button
			connected.set(false);
			// stop here
			return;
		}
    	// everything ok, we connected
		connected.set(true);
    	
    }
    
    public boolean isAutoconnecting() {
    	return autoconnectCheckBox.isSelected();
    }
    
    public void enableManualConnection() {
    	connectButton.setDisable(false);
    }
}
