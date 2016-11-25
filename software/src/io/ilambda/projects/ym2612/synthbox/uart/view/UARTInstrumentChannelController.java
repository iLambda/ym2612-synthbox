package io.ilambda.projects.ym2612.synthbox.uart.view;

import java.io.File;
import java.io.IOException;

import io.ilambda.projects.ym2612.synthbox.uart.FileOperation;
import javafx.fxml.*;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.stage.*;

public class UARTInstrumentChannelController {
	@FXML
	private Slider channelSlider;
	
	private UARTMainViewController parent;
	private FileOperation operation;
	private File file;
	
	/**
     * Initializes the controller class. This method is automatically called
     * after the fxml file has been loaded.
     */
    @FXML
    private void initialize() {
    	
    }

    @FXML
    private void ok() {
    	// close this one
    	close();
		// open dialog
		try {
			Stage dialog = new Stage();
			FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("UARTInstrumentLoadView.fxml"));
			dialog.setScene(new Scene(fxmlLoader.load()));
			UARTInstrumentLoadController controller = fxmlLoader.getController();
			controller.setParent(parent);
			controller.setOperation(operation);
			controller.setFile(file);
			controller.setChannel((int)channelSlider.getValue());
			dialog.initOwner(((Stage)channelSlider.getScene().getWindow()).getOwner());
			dialog.setTitle("Loading");
			dialog.setResizable(false);
			dialog.initModality(Modality.APPLICATION_MODAL); 
			dialog.showAndWait();
		} catch (IOException e) {
			e.printStackTrace();
		}
    }

    @FXML
    private void close() {
		// close
		((Stage)channelSlider.getScene().getWindow()).close();
    }

	public void setParent(UARTMainViewController parent) {
		this.parent = parent;
	}

	public void setOperation(FileOperation op) {
		this.operation = op;
	}

	public void setFile(File file) {
		this.file = file;
	}
}
