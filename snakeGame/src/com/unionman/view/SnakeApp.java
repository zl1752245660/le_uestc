package com.unionman.view;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;

import javax.swing.JFrame;

import com.unionman.control.GameController;
import com.unionman.entity.Grid;

public class SnakeApp extends Thread{
	
	private Grid grid;
	private int currentNumber = 0;
	private GameController controller;
	private JFrame window;
	
	public void init() {
		
		grid = new Grid(400, 400);
		window = new JFrame();
		window.setPreferredSize(new Dimension(405, 410));
		Container component = window.getContentPane();
		
		GameView gameView = new GameView(grid);
		gameView.init();
		
		controller = new GameController(gameView, grid);
		window.addKeyListener(controller);
		new Thread(controller).start();
		
		component.add(gameView.getCanvas(),BorderLayout.CENTER);
		window.setTitle("Ã∞≥‘…ﬂ”Œœ∑");
		window.pack();
        window.setResizable(false);
        window.setLocationRelativeTo(null);
        window.setVisible(true);
	}
	
	@Override
	public void run() {
		while(controller.running) {
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			if(grid.getNumber() != currentNumber) {
				currentNumber = grid.getNumber();
				StringBuilder sb = new StringBuilder();
				sb.append("Ã∞≥‘…ﬂ”Œœ∑");
				sb.append("    ª˝∑÷£∫");
				sb.append(currentNumber);
				window.setTitle(sb.toString());
			}
			
		}
		super.run();
	}

	public static void main(String[] args) {
		SnakeApp app = new SnakeApp();
		app.init();
		app.start();
	}
}
