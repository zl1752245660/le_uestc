package com.unionman.entity;

public class Node {

	private final int x;
	private final int y;
	private final int width = 20;
	private final int height = 20;
	
	public Node (int x,int y) {
		this.x = x;
		this.y = y;
	}
	
	public int getX() {
		return x;
	}
	
	public int getY() {
		return y;
	}
}
