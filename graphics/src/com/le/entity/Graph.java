package com.le.entity;

import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Queue;
import java.util.Stack;

import com.le.util.Constants;

public class Graph<T> {

	private Map<T, Vertex<T>> vertexs = null;
	private int edgeNum;
	
	public Graph() {
		this.vertexs = new HashMap<>();
		edgeNum = 0;
	}
	
	public void addVertex(T vertex_T) {
		vertexs.put(vertex_T, new Vertex<T>(vertex_T));
	}
	
	public void addEdge(T start, T end, int weight) {
		Vertex<T> startVertex = vertexs.get(start);
		Vertex<T> endVertex = vertexs.get(end);
		if(startVertex != null && endVertex != null) {
			startVertex.connect(endVertex, weight);
			edgeNum ++;
		}
	}
	
	public void addEdge(T start, T end) {
		addEdge(start, end, 0);
	}
	
	public boolean hasEdge(T start, T end) {
		Vertex<T> startVertex = vertexs.get(start);
		Vertex<T> endVertex = vertexs.get(end);
		if(startVertex == null || endVertex == null || startVertex.hasNeighbor()) {
			return false;
		}
		Iterator<Vertex<T>> vertexIterator = startVertex.getNeighborIterator();
		while(vertexIterator.hasNext()) {
			Vertex<T> neiVertex = vertexIterator.next();
			if(neiVertex.equals(endVertex)) {
				return true;
			}
		}
		return false;
	}
	
	public int getVertexNumber() {
		return vertexs.size();
	}
	
	public void BFS(Vertex<T> source) {
		for (Entry<T, Vertex<T>> entry : vertexs.entrySet()) {
			if(! source.equals(source)) {
				Vertex<T> vertex = entry.getValue();
				vertex.setColor(Constants.WHITE);
				vertex.setDepth(Integer.MAX_VALUE);
			}
		}
		source.setColor(Constants.GRAY);
		source.setDepth(0);
		source.setPreviousVertex(null);
		
		Queue<Vertex<T>> vertexQueue = new LinkedList<>();
		vertexQueue.offer(source);
		while(vertexQueue.size() > 0) {
			Vertex<T> vertex = vertexQueue.poll();
			Vertex<T> sonVertex = null;
			while((sonVertex = vertex.getUnVisitedVertex()) != null) {
				sonVertex.setColor(Constants.GRAY);
				sonVertex.setDepth(vertex.getDepth() + 1);
				sonVertex.setPreviousVertex(vertex);
				vertexQueue.offer(sonVertex);
			}
			vertex.setColor(Constants.BLACK);
		}
	}
	
	private int time;
	
	public void DFS() {
		for(Entry<T, Vertex<T>> entry : vertexs.entrySet()) {
			Vertex<T> vertex = entry.getValue();
			vertex.setColor(Constants.WHITE);
			vertex.setPreviousVertex(null);
		}
		time = 0;
		for(Entry<T, Vertex<T>> entry : vertexs.entrySet()) {
			Vertex<T> vertex = entry.getValue();
			if(vertex.getColor() == Constants.WHITE) {
				DFS_VISIT(vertex);
			}
		}
	}
	
	private void DFS_VISIT(Vertex<T> vertex) {
		time = time + 1;
		vertex.setD(time);
		vertex.setColor(Constants.GRAY);
		Vertex<T> sonVertex = null;
		while((sonVertex = vertex.getUnVisitedVertex()) != null) {
			sonVertex.setPreviousVertex(vertex);
			DFS_VISIT(sonVertex);
		}
		vertex.setColor(Constants.BLACK);
		time ++;
		vertex.setF(time);
	}
	/**
	 * 拓扑排序，利用DFS深度搜索技术，时间复杂度为O(V+E)
	 * @return
	 */
	public Stack<Vertex<T>> topologicalSort() {
		//创建一个空的一个结点的栈，用来保存节点数据
		Stack<Vertex<T>> vertexStack = new Stack<>();
		
		for(Entry<T, Vertex<T>> entry : vertexs.entrySet()) {
			Vertex<T> vertex = entry.getValue();
			vertex.setColor(Constants.WHITE);
			vertex.setPreviousVertex(null);
		}
		time = 0;
		for(Entry<T, Vertex<T>> entry : vertexs.entrySet()) {
			Vertex<T> vertex = entry.getValue();
			if(vertex.getColor() == Constants.WHITE) {
				topo_DFS_VISIT(vertex,vertexStack);
			}
		}
		return vertexStack;
	}
	
	private void topo_DFS_VISIT(Vertex<T> vertex , Stack<Vertex<T>> vertexStack) {
		time = time + 1;
		vertex.setD(time);
		vertex.setColor(Constants.GRAY);
		Vertex<T> sonVertex = null;
		while((sonVertex = vertex.getUnVisitedVertex()) != null) {
			sonVertex.setPreviousVertex(vertex);
			topo_DFS_VISIT(sonVertex , vertexStack);
		}
		vertex.setColor(Constants.BLACK);
		time ++;
		vertex.setF(time);
		//根据节点扫描完成时间依次将节点推到栈中
		vertexStack.push(vertex);
	}
	
	public void printDFSPath(Vertex<T> source , Vertex<T> vertex) {
		if(source.equals(vertex)) {
			System.out.println("lable : " + vertex.getLable() + " , 开始: " + vertex.getD() + " 结束 : "+vertex.getF());
		} else if(vertex.getPreviousVertex() == null){
			System.out.println("path no exist!");
		} else {
			printDFSPath(source, vertex.getPreviousVertex());
			System.out.println("lable : " + vertex.getLable() + " , 开始: " + vertex.getD() + " 结束: "+vertex.getF());
		}
	}
	
	public void printBFSPath(Vertex<T> source , Vertex<T> vertex) {
		if(source.equals(vertex)) {
			System.out.println("lable : " + vertex.getLable() + " , depth : " + vertex.getDepth());
		} else if(vertex.getPreviousVertex() == null){
			System.out.println("path no exist!");
		} else {
			printBFSPath(source, vertex.getPreviousVertex());
			System.out.println("lable : " + vertex.getLable() + " , depth : " + vertex.getDepth());
		}
	}
	
	public Vertex<T> getVertex(T lable) {
		return vertexs.get(lable);
	}
	
	public void printAllVertext() {
		for(Entry<T, Vertex<T>> entry : vertexs.entrySet()) {
			Vertex<T> vertex = entry.getValue();
			System.out.println(vertex.getLable()+" "+vertex.getColor()+" "+vertex.getDepth());
		}
	}
	
	public void printDFSAllVertext() {
		for(Entry<T, Vertex<T>> entry : vertexs.entrySet()) {
			Vertex<T> vertex = entry.getValue();
			System.out.println(vertex.getLable()+" "+vertex.getColor()+" "+vertex.getD() + " "+vertex.getF());
		}
	}
	
	public void printTopoSort(Stack<Vertex<T>> vertexStack) {
		System.out.println("size = "+vertexStack.size());
		while(!vertexStack.empty()) {
			Vertex<T> vertex = vertexStack.pop();
			System.out.println("lable : " + vertex.getLable() + " f : " + vertex.getF());
		}
		
	}
}
