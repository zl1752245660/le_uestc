package com.unionman.entity;

import java.util.List;

public class Grid {

	private final int width;
	private final int height;
	public boolean[][] status;
	private Snake snake;
	private Node food;
	private Direction snakeDirection = Direction.LEFT;
	private int number = 0;
	
	public Grid(int width,int height) {
		this.width = width;
		this.height = height;
		status = new boolean[width/20 + 1][height/20 + 1];
		initSnake();
		createFood();
	}
	
	public Snake initSnake() {
		snake = new Snake(snakeDirection);
		
		int x = 200;
		int y = 200;
		Node node = null;
		for (int i = 0; i < 5; i++) {
			x = x + 20;
			y = y;
			node = new Node(x, y);
			
			snake.addTail(node);
			status[x/20][y/20] = true;
		}
		
		return snake;
	}
	
	public void createFood() {
		int x = (int) (Math.random() * width);
		int y = (int) (Math.random() * height);
		
		if(status[x/20][y/20] == true) {
			createFood();
		} else {
			food = new Node((x/20)*20, (y/20)*20);
		}
	}
	
	public Node getFood() {
		return food;
	}
	
	public Snake getSnake() {
		return snake;
	}
	
	public void changeDirection(Direction dir) {
		
		switch (snakeDirection) {
		case UP:
		case DOWN:
			if(dir == Direction.UP || dir == Direction.DOWN) {
				
			} else {
				snakeDirection = dir;
				snake.changeDirection(dir);
			}
			break;
		case RIGHT:
		case LEFT:
			if(dir == Direction.RIGHT || dir == Direction.LEFT) {
				
			} else {
				snakeDirection = dir;
				snake.changeDirection(dir);
			}
			break;
		default:
			break;
		}
		
	}
	
	public void snakeMove() {
		snake.move();
		refreshAreaStatus();
		if(snake.eat(food)) {
			number ++;
			System.out.println("吃到食物了");
			createFood();
		}
	}
	
	private void refreshAreaStatus() {
		List<Node> body = snake.getBody();
		
		for (int i = 0; i < status.length; i++) {
			for(int j = 0; j <status[i].length; j++) {
				status[i][j] = false;
			}
		}
		Node node = null;
		for (int i = 0; i < body.size(); i++) {
			node = body.get(i);
			status[node.getX()/20][node.getY()/20] = true;
		}
	}
	
	public int getNumber() {
		return number;
	}
}
