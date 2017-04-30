package com.le.entity;

import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;

public class NeighborIterator<T> implements Iterator<Vertex<T>> {

	private Iterator<Edge<T>> edgesIterator; 
	
	public NeighborIterator(List<Edge<T>> edgeList) {
		edgesIterator = edgeList.iterator();
	}
	
	@Override
	public boolean hasNext() {
		return edgesIterator.hasNext();
	}

	@Override
	public Vertex<T> next() {
		Vertex<T> vertex = null;
		if(edgesIterator.hasNext()) {
			Edge<T> edge = edgesIterator.next();
			vertex = edge.getVertex();
			return vertex;
		} else {
			throw new NoSuchElementException();
		}
	}
}
