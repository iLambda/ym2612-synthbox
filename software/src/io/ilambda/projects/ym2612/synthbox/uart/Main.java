package io.ilambda.projects.ym2612.synthbox.uart;

import java.io.IOException;

import io.ilambda.projects.ym2612.synthbox.uart.view.UARTMainViewController;
import javafx.application.*;
import javafx.fxml.*;
import javafx.scene.*;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.stage.*;
import jssc.SerialPortException;

public class Main extends Application {

	@Override
	public void start(Stage stage) {
		try {
			Parent root = FXMLLoader.load(getClass().getResource("view/UARTMainView.fxml"));
	        stage.setTitle("YM2612 Synthbox UART Transmitter");
	        stage.setScene(new Scene(root));
	        stage.setResizable(false);
	        stage.show();
		} catch (IOException e) {
			e.printStackTrace();
		}	
	}

	@Override
	public void stop(){
	    // closing port
		if (UARTMainViewController.usedPort.get() != null && UARTMainViewController.usedPort.get().isOpened()) {
			try {
				UARTMainViewController.usedPort.get().closePort();
			} catch (SerialPortException e) {
				// display dialog
				Alert alert = new Alert(AlertType.ERROR);
				alert.setTitle("Error!");
				alert.setHeaderText("An error occured while closing the serial port. The port might remain open even after application is closed.");
				alert.setContentText(e.getMessage() + "\n\n" + e.getStackTrace());
				alert.showAndWait();
			}
		}
	}
	
	public static void main(String[] args) {
		launch(args);
	}
}
