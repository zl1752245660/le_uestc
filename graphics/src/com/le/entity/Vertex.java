package com.le.entity;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

import com.le.util.Constants;
/**
 * 有向图的节点类
 * @author le.zhang
 *
 * @param <T>
 */
public class Vertex<T> {

	private T lable;		//当前节点的标识数据
	private int color;		//当前节点的颜色
	private Vertex<T> previousVertex;		//该节点的前驱结点
	private List<Edge<T>> edgeList;		//保存与该节点连接的边
	private int depth;		//深度 ，在BFS广度优先搜索中用到
	
	private int d;		//时间戳，代表第一次该节点被发现的时间，在深度优先搜索的时候用到
	private int f;		//时间戳，代表搜索完成对该节点的邻接链表扫描的时间
	
	public Vertex(T _lable) {
		this.lable = _lable;
		this.color = Constants.WHITE;
		this.previousVertex = null;
		this.edgeList = new LinkedList<Edge<T>>();
		this.depth = Integer.MAX_VALUE;
	}
	
	/**
	 * 将当前节点和目标节点相连，用边Edge保存
	 * @param endVertex
	 * @param weight
	 * @return
	 */
	public boolean connect(Vertex<T> endVertex ,int weight) {
		boolean result = false;
		if(!this.equals(endVertex)) {
			Iterator<Vertex<T>> neighborIterator = this.getNeighborIterator();
			boolean identical = false;
			while(neighborIterator.hasNext()) {
				Vertex<T> vertex = neighborIterator.next();
				if(vertex.equals(endVertex)) {
					identical = true;
					break;
				}
			}
			if(!identical) {
				Edge<T> edge = new Edge<>(endVertex, weight);
				edgeList.add(edge);
				result = true;
			} else {
				result = false;
			}
		} else {
			result = false;
		}
		return result;
	}
	
	public NeighborIterator<T> getNeighborIterator() {
		return new NeighborIterator<>(edgeList);
	}

	public T getLable() {
		return this.lable;
	}
	
	@Override
	public boolean equals(Object obj) {
		if(!(obj instanceof Vertex)) {
			return false;
		} else {
			Vertex<T> vertext = (Vertex<T>)obj;
			return vertext.getLable().equals(getLable());
		}
	}
	
	public void setPreviousVertex(Vertex<T> vertex) {
		this.previousVertex = vertex;
	}
	
	public Vertex<T> getPreviousVertex() {
		return this.previousVertex;
	}
	
	public void setColor(int color) {
		this.color = color;
	}
	
	public int getColor() {
		return this.color;
	}
	
	public boolean hasNeighbor() {
		return edgeList.isEmpty();
	}
	
	public Iterator getWeightIterator() {
		return new WeightIterator<>(edgeList);
	}
	
	/**
	 * 获得与当前结点相连接的节点中没有被访问的节点
	 * @return
	 */
	public Vertex<T> getUnVisitedVertex() {
		NeighborIterator<T> neighborIterator = this.getNeighborIterator();
		Vertex<T> vertex = null;
		while(neighborIterator.hasNext()) {
			vertex = neighborIterator.next();
			if(vertex.getColor() == Constants.WHITE) {
				return vertex;
			}
		}
		return null;
	}
	
	public void setDepth(int _depth) {
		this.depth = _depth;
	}
	
	public int getDepth() {
		return this.depth;
	}

	public int getD() {
		return d;
	}

	public void setD(int d) {
		this.d = d;
	}

	public int getF() {
		return f;
	}

	public void setF(int f) {
		this.f = f;
	}
}
