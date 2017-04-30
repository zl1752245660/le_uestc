package com.le.entity;

import java.util.Iterator;
import java.util.List;
import java.util.NoSuchElementException;

public class WeightIterator<T> implements Iterator{

	private Iterator<Edge<T>> edgesIterator;
	
	public WeightIterator(List<Edge<T>> edgeList) {
		this.edgesIterator = edgeList.iterator();
	}
	
	@Override
	public boolean hasNext() {
		return edgesIterator.hasNext();
	}

	@Override
	public Object next() {
		Object weight = null;
		if(edgesIterator.hasNext()) {
			weight = edgesIterator.next().getWeight();
			return weight;
		} else {
			throw new NoSuchElementException();
		}
	}

}
