package com.le.entity;

public class Edge<T> {

	private Vertex<T> vertex;
	private int weight;
	
	public Edge(Vertex<T> _vertex,int _weight) {
		this.vertex = _vertex;
		this.weight = _weight;
	}
	
	public Vertex<T> getVertex() {
		return vertex;
	}
	
	public int getWeight() {
		return weight;
	}
}
