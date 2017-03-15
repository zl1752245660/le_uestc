package com.unionman.view;

import java.awt.Color;
import java.awt.Graphics;
import java.util.List;

import javax.swing.JPanel;

import com.unionman.entity.Grid;
import com.unionman.entity.Node;
import com.unionman.entity.Snake;

public class GameView {

	private final Grid grid;
	private JPanel canvas;
	
    public GameView(Grid grid) {
        this.grid = grid;
    }

    public void init() {
        canvas = new JPanel() {
            @Override
            public void paintComponent(Graphics graphics) {
                drawGridBackground(graphics);
                drawSnake(graphics, grid.getSnake());
                drawFood(graphics, grid.getFood());
            }
        };
    }
    
    public void draw() {
        canvas.repaint();
    }
    
    public JPanel getCanvas() {
        return canvas;
    }

    public void drawSnake(Graphics graphics, Snake snake) {
    	List<Node> nodes = snake.getBody();
    	for (Node node : nodes) {
    		graphics.setColor(Color.BLACK);
    		//System.out.println(node.getX() +"  "+node.getY());
			graphics.fillRect(node.getX(), node.getY(), 20, 20);
			graphics.setColor(Color.WHITE);
			graphics.fillRect(node.getX() + 1 , node.getY() + 1, 18, 18);
		}
    }

    public void drawFood(Graphics graphics, Node food) {
    	graphics.setColor(Color.RED);
    	graphics.fillOval(food.getX(), food.getY(), 20, 20);
    }

    public void drawGridBackground(Graphics graphics) {
    	graphics.setColor(Color.BLACK);
    	graphics.fillRect(0, 0, 400, 400);
    }
}
