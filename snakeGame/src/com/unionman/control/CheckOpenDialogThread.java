package com.unionman.control;

import javax.swing.JDialog;

import com.unionman.uti.Constant;
import com.unionman.view.FinishDialog;
import com.unionman.view.SnakeApp;

public class CheckOpenDialogThread extends Thread {

	private SnakeApp app;
	
	public CheckOpenDialogThread(SnakeApp app) {
		this.app = app;
	}
	
	@Override
	public void run() {
		while(true) {
			if(Constant.openDialog) {
				//System.out.println("ºÏ≤‚÷–£¨£¨openDialog = "+Constant.openDialog);
				app.getCheckThread().stop();
				app.getGameControlThread().stop();
				Constant.openDialog = false;
				FinishDialog dialog = new FinishDialog();
				dialog.setView(app);
				dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
				
				dialog.setVisible(true);
				
				
			}
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	
}
