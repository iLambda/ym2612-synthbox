package io.ilambda.projects.ym2612.synthbox.uart.view;

import java.io.File;

import io.ilambda.projects.ym2612.synthbox.uart.FileOperation;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ProgressBar;
import javafx.scene.control.Slider;
import javafx.scene.control.Alert.AlertType;
import javafx.stage.Stage;

public class UARTInstrumentLoadController {

	@FXML
	private ProgressBar progressBar;
	
	private UARTMainViewController parent;
	private FileOperation operation;
	private int channel;
	private File file;
	
	/**
     * Initializes the controller class. This method is automatically called
     * after the fxml file has been loaded.
     */
    @FXML
    private void initialize() {
    	progressBar.setProgress(ProgressBar.INDETERMINATE_PROGRESS);
    }

    @FXML
    private void ok() {
    	// open other window
		
    	// close this one
		((Stage)progressBar.getScene().getWindow()).close();
    }

    @FXML
    private void close() {
    	// warning message
		if (operation == FileOperation.Import && progressBar.getProgress() > 0) {
			Alert alert = new Alert(AlertType.WARNING);
			alert.setTitle("Warning!");
			alert.setHeaderText("The import has been interrupted.");
			alert.setContentText("Only a part of the data (" + ((int)progressBar.getProgress()) + "%) has been written to the device. Device memory may be incorrect values.");
			alert.showAndWait();
		}
		
		// close
		((Stage)progressBar.getScene().getWindow()).close();
    }

	public void setParent(UARTMainViewController parent) {
		this.parent = parent;
	}

	public void setOperation(FileOperation op) {
		this.operation = op;
	}
	
	public void setChannel(int ch) {
		this.channel = ch;
	}

	public void setFile(File file) {
		this.file = file;
	}
}
