package com.unionman.entity;

import java.util.LinkedList;
import java.util.List;

public class Snake {

	private List<Node> body = new LinkedList<Node>();
	private Direction dir = Direction.LEFT;
	
	public Snake() {
		
	}
	
	public Snake(Direction dir) {
		this.dir = dir;
	}
	
	public boolean eat(Node food) {
		Node firstNode = getHead();
		boolean isEat = false;
		switch (dir) {
		case UP:
			
			if((firstNode.getY() == food.getY() + 20) && (firstNode.getX() == food.getX()) ) {
				isEat = true;
			} else {
				isEat = false;
			}
			break;
		case DOWN:
			
			if((firstNode.getY() + 20 >= food.getY()) && (firstNode.getX() == food.getX() )) {
				isEat = true;
			} else {
				isEat = false;
			}
			break;
		case RIGHT:
			if((firstNode.getX() + 20 >= food.getX()) && (firstNode.getY() == food.getY())) {
				isEat = true;
			} else {
				isEat = false;
			}
			break;
		case LEFT:
			if((firstNode.getX() <= food.getX() + 20) && (firstNode.getY() == food.getY())) {
				isEat = true;
			} else {
				isEat = false;
			}
			break;
		default:
			break;
		}
		
		if(isEat){
			addNode();
		}
		
		return isEat;
		
	}
	
	public void move() {
		
		body.remove(body.size() - 1);
		addNode();
	}
	
	public Node getHead() {
		return body.get(0);
	}
	
	public void addNode() {
		Node node = body.get(0);
		switch(dir) {
		case DOWN:
			
			if (node.getY() == 400) {
				node = new Node( node.getX() ,-20);
			}
			body.add(0, new Node(node.getX(), node.getY() + 20));
			
			break;
			
		case UP:
			
			if (node.getY() == 0) {
				node = new Node( node.getX() ,400);
			}
			body.add(0, new Node(node.getX(), node.getY() - 20));
			
			break;
			
		case LEFT:
			
			if (node.getX() == 0) {
				node = new Node(400, node.getY());
			}
			body.add(0, new Node(node.getX() - 20 , node.getY()));
			
			break;
			
		case RIGHT:
			
			if (node.getX() == 400) {
				node = new Node(-20, node.getY());
			}
			body.add(0, new Node(node.getX() + 20 , node.getY()));
			
			break;
		
		default:
			break;
		}
	}
	
	public Node addTail(Node node) {
		
		body.add(node);
		return node;
	}
	
	public List<Node> getBody() {
		return body;
	}
	
	public void changeDirection(Direction dir) {
		this.dir = dir;
	}
}
