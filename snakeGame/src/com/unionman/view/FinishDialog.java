package com.unionman.view;

import java.awt.BorderLayout;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;

import com.unionman.uti.Constant;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class FinishDialog extends JDialog {

	private final JPanel contentPanel = new JPanel();

	private SnakeApp app;
	
	public void setView(SnakeApp _app) {
		this.app = _app;
	}
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		try {
			FinishDialog dialog = new FinishDialog();
			dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
			dialog.setVisible(true);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * Create the dialog.
	 */
	public FinishDialog() {
		setBounds(580, 300, 213, 128);
		
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setLayout(new FlowLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		{
			JLabel label = new JLabel("\u649E\u5230\u81EA\u5DF1\u4E86");
			contentPanel.add(label);
		}
		{
			JLabel label = new JLabel("\u662F\u5426\u91CD\u65B0\u542F\u52A8\u6E38\u620F");
			contentPanel.add(label);
		}
		{
			JPanel buttonPane = new JPanel();
			buttonPane.setLayout(new FlowLayout(FlowLayout.RIGHT));
			getContentPane().add(buttonPane, BorderLayout.SOUTH);
			{
				JButton okButton = new JButton("OK");
				okButton.addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						FinishDialog.this.dispose();
						app.init();
						Constant.speed = 200;
					}
				});
				okButton.setActionCommand("OK");
				
				buttonPane.add(okButton);
			
				getRootPane().setDefaultButton(okButton);
			}
			{
				JButton cancelButton = new JButton("Cancel");
				cancelButton.setActionCommand("Cancel");
				cancelButton.addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						System.exit(-1);
					}
				});
				buttonPane.add(cancelButton);
			}
		}
	}

}
