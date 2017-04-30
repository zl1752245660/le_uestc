package com.le.entity;

/**
 * 图中的边类，保存了边的终点和边的权重值
 * @author le.zhang
 *
 * @param <T>
 */
public class Edge<T> {

	//边上的终点
	private Vertex<T> vertex;
	//边的权重值
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
