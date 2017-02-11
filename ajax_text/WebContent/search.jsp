<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">

	<style type="text/css">
		#mydiv {
			position: absolute;
			left: 50%;
			top: 50%;
			margin-left: -250px;
			margin-top: -40px;
		}
		
		.mouseOver {
			background-color: #E5E5E5; 
			cursor: pointer;
		}
		
		.mouseOut {
			background-color: #FFFAFA;
		}
		
	</style>
	
	<script type="text/javascript">
		
		var xmlHttp;
	
		function getMoreContent() {
			var content = document.getElementById("keyword");
			var content_value = content.value;
			if(content_value == "") {
				clearShowData();
				return;
			}
			
			xmlHttp = createXmlHttp();
			
			var url = "search?keyword="+escape(content_value);
			xmlHttp.open("GET",url,true);
			//绑定回调函数
			xmlHttp.onreadystatechange = callback;
			xmlHttp.send();
		}
		
		function callback() {
			if(xmlHttp.readyState == 4) {
				if(xmlHttp.status == 200) {
					var result = xmlHttp.responseText;
					var json = eval("("+result+")");
					clearShowData();
					setContent(json);
				}
			}
		}
		
		function setContent(contents) {
			if(contents)
			
			var size = contents.length;
			if(size > 0) {
				setLoaction();
			}
			for(var i = 0; i < size; i++) {
				var nextNode = contents[i];
				var tr = document.createElement("tr");
				var td = document.createElement("td");
				td.setAttribute("border", "0");
				td.setAttribute("bgcolor", "#FFFAFA");
				
				//给td绑定鼠标滑过的事件
				td.onmouseover = function() {
					this.className = 'mouseOver';
				};
				
				td.onmouseout = function() {
					this.className = 'mouseOut';
				};
				
				td.onmousedown = function() {
					document.getElementById("keyword").value = this.innerText;
				};
				
				var text = document.createTextNode(nextNode);
				td.appendChild(text);
				tr.appendChild(td);
				document.getElementById("content_table_body").appendChild(tr);
				
				
			}
			
		}
		
		
		function createXmlHttp() {
			var xmlHttp;
			if(window.XMLHttpRequest) {
				xmlHttp = new XMLHttpRequest();
			}
			if(window.ActiveXObject) {
				xmlHttp = new ActiveXObject("Microsoft:XMLHTTP");
				if(!xmlHttp) {
					xmlHttp = new ActiveXObject("Msxml2:XMLHTTP");
				}
			}
			return xmlHttp;
		}
	
		function clearShowData() {
			var tbody = document.getElementById("content_table_body");
			var size = tbody.childNodes.length;
			for(var i = size - 1;i >= 0; i -- ) {
				tbody.removeChild(tbody.childNodes[i]);
			}
			document.getElementById("popDiv").style.border = "none";
		}
		
		function keywordBlur() {
			clearShowData();
		}
		
		function setLoaction() {
			var content = document.getElementById("keyword");
			var width = content.offsetWidth;
			//alert(width);
			var height = content.offsetHeight;
			var left = content["offsetLeft"];
			var top = content["offsetTop"] + height;
			var pop_body = document.getElementById("popDiv");
			pop_body.style.border = "black 1px solid";
			pop_body.style.left = left + "px";
			pop_body.style.top = top + "px";
			pop_body.style.width = width + "px";
			document.getElementById("content_table").style.width = width + "px";
		}
		
	</script>
	
</head>
<body>

	<div id = "mydiv">
		<input type = "text" size = "50" id = "keyword" onkeyup="getMoreContent()" onblur="keywordBlur()"/>
		<input type = "button" value = "百度一下" width="50px"/>
		
		
		<div id = "popDiv">
			<table id = "content_table" bgcolor="#FFFAFA" border="0" cellspacing="0"
				cellpadding="0">
				
				<tbody id = "content_table_body">
					 
	
					 
				</tbody>
				
			</table>
		</div>
	</div>

</body>
</html>