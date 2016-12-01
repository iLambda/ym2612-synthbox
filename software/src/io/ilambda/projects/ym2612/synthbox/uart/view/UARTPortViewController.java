package io.ilambda.projects.ym2612.synthbox.uart.view;

import javafx.collections.*;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.Alert.AlertType;
import javafx.stage.Stage;
import jssc.*;

public class UARTPortViewController {
	
	@FXML
	private ComboBox<String> comComboBox;
	@FXML
	private Button okButton;
	
	private UARTMainViewController parent;
	
	/**
     * Initializes the controller class. This method is automatically called
     * after the fxml file has been loaded.
     */
    @FXML
    private void initialize() {
    	// set ports list
    	comComboBox.setItems(FXCollections.observableArrayList(SerialPortList.getPortNames()));
    	// if no com port detected
    	if (comComboBox.getItems().size() <= 0) {
    		// disable
    		comComboBox.setDisable(true);
    		// alert
			Alert alert = new Alert(AlertType.ERROR);
			alert.setTitle("Error!");
			alert.setHeaderText("No COM port has been detected.");
			alert.setContentText("The software didn't detect any COM port on your device.\nIf you indeed have COM ports, try restarting your machine.");
			alert.showAndWait();
			// set button text to exit	
			okButton.setText("Exit");
    	}
    }
    
    /**
     * When a new option is selected
     */
    @FXML
    private void selectPort() {
    	// close old port if opened
    	if (UARTMainViewController.usedPort.get() != null && UARTMainViewController.usedPort.get().isOpened()) {
    		try {
				UARTMainViewController.usedPort.get().closePort();
			} catch (SerialPortException e) {
				// display dialog
				Alert alert = new Alert(AlertType.ERROR);
				alert.setTitle("Error!");
				alert.setHeaderText("An error occured while closing the serial port " + e.getPortName() + ". The port might remain open even after application is closed.");
				alert.setContentText(e.getMessage() + "\n\n" + e.getStackTrace());
				alert.showAndWait();
			}
    	}
    	// set port if there is ports
    	if (comComboBox.getItems().size() > 0) {
        	UARTMainViewController.usedPort.set(new SerialPort(comComboBox.getValue()));
        	parent.updatePort();
    	}
    }

    
    /**
     * Close the selection
     */
    public void close() {
    	// if ports
    	if (comComboBox.getItems().size() > 0) {
        	// set port
        	if (parent.isAutoconnecting()) {
        		parent.listenPort();
        	} else {
        		parent.enableManualConnection();
        	}  		
    	}   	

    	// close
    	((Stage)comComboBox.getScene().getWindow()).close();
    }
    
	public void setParent(UARTMainViewController parent) {
		this.parent = parent;
	}
    
    
}
