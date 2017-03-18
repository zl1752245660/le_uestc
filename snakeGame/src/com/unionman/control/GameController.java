package com.unionman.control;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.MoveAction;

import com.unionman.entity.Direction;
import com.unionman.entity.Grid;
import com.unionman.uti.Constant;
import com.unionman.view.GameView;

public class GameController implements KeyListener,Runnable{
	
	private GameView gameView;
	private Grid grid;
	public boolean running = true;
	
	
	public GameController(GameView gameView, Grid grid) {
		this.gameView = gameView;
		this.grid = grid;
	}
	
	@Override
	public void keyTyped(KeyEvent e) {
		
	}

	@Override
	public void keyPressed(KeyEvent e) {
		int key = e.getKeyCode();
		switch(key) {
		case KeyEvent.VK_UP:
			grid.changeDirection(Direction.UP);
			break;
		
		case KeyEvent.VK_DOWN:
			grid.changeDirection(Direction.DOWN);
			break;
			
		case KeyEvent.VK_RIGHT:
			grid.changeDirection(Direction.RIGHT);
			break;
			
		case KeyEvent.VK_LEFT:
			grid.changeDirection(Direction.LEFT);
			break;
		}
	}

	@Override
	public void keyReleased(KeyEvent e) {
		
	}

	@Override
	public void run() {
		while (running) {
			try {
				Thread.sleep(Constant.speed);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			grid.snakeMove();
			if(grid.getSnake().isHitBody()) {
				Constant.openDialog = true;
				break;
			}
			gameView.draw();
		}
	}
}
