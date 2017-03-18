package com.unionman.view;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;

import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;

import com.unionman.control.CheckOpenDialogThread;
import com.unionman.control.GameController;
import com.unionman.entity.Grid;
import com.unionman.uti.Constant;

public class SnakeApp {

	private Grid grid;
	private int currentNumber = 0;
	private GameController controller;
	private JFrame window;
	private Thread controlThread;
	private Thread checkCountThread;
	
	public SnakeApp() {
		this.window = new JFrame();
	}

	public void init() {

		grid = new Grid(400, 400);
		window.setPreferredSize(new Dimension(405, 430));
		Container component = window.getContentPane();

		GameView gameView = new GameView(grid);
		gameView.init();

		controller = new GameController(gameView, grid);
		window.addKeyListener(controller);
		controlThread = new Thread(controller);
		controlThread.start();

		component.add(gameView.getCanvas(), BorderLayout.CENTER);
		window.setTitle("Ã∞≥‘…ﬂ”Œœ∑");
		window.pack();
		window.setResizable(false);
		window.setLocationRelativeTo(null);
		window.setDefaultCloseOperation(window.EXIT_ON_CLOSE);
		window.setVisible(true);
		checkCountThread = new Thread(checkThread);
		checkCountThread.start();
	}

	Runnable checkThread = new Runnable() {

		@Override
		public void run() {
			while (controller.running) {
				try {
					Thread.sleep(100);
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				if (grid.getNumber() != currentNumber) {
					currentNumber = grid.getNumber();
					StringBuilder sb = new StringBuilder();
					sb.append("Ã∞≥‘…ﬂ”Œœ∑");
					sb.append("    ª˝∑÷£∫");
					sb.append(currentNumber);
					window.setTitle(sb.toString());
					Constant.speed = Constant.speed - Constant.speed/20;
				}
			}
		}
	};

	public Thread getCheckThread() {
		return checkCountThread;
	}
	
	public Thread getGameControlThread() {
		return controlThread;
	}
	
	public static void main(String[] args) {
		SnakeApp app = new SnakeApp();
		app.init();
		Thread checkThread = new CheckOpenDialogThread(app);
		checkThread.start();
	}
}
