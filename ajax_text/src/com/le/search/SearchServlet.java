package com.le.search;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import net.sf.json.JSONArray;

public class SearchServlet extends HttpServlet {

	private static List<String> datas = new ArrayList<String>();
	
	static {
		
		datas.add("ajax");
		datas.add("ariport");
		datas.add("apple");
		datas.add("ari");
		
		datas.add("blue");
		datas.add("black");
		datas.add("baidu");
		datas.add("beyond");
		
		datas.add("cook");
		datas.add("coffe");
		datas.add("chrome");
		
	}
	
	@Override
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		
		String keyword = request.getParameter("keyword");
		List<String> result = getData(keyword);
		
		JSONArray jsonArray = JSONArray.fromObject(result);
		System.out.println(jsonArray);
		response.getWriter().write(jsonArray.toString());
	}

	private List<String> getData(String keyword) {
		List<String> result = new ArrayList<String>();
		for (String data : datas) {
			if(data.contains(keyword)) {
				System.out.println(data+"  "+keyword);
				result.add(data);
			}
		}
		return result;
	}
}
