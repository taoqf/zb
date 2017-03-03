(function(){
	window.jsfunc = function(){
		alert('abc');
	};
	btnplay.onclick = function(e){
		external.callcpp("switch", '');
	};
	btnexit.onclick = function(e){
		external.callcpp('exit', '')
	};
	btnmix.onclick = function(e){
		external.callcpp('miximum', '')
	};
	btntest.onclick = function(e){
		var data = [{
			img: 'res:/PNG/#134',
			name: '屏幕截图1.jpg'
		},{
			img: 'res:/PNG/#135',
			name: '背景图.jpg'
		},{
			img: 'res:/PNG/#135',
			name: '素材图.jpg'
		}];
		var tpl = '{{~it :v:index}}<div><img src="{{=v.img}}" alt=""><span>{{=v.name}}</span><img src="res:/PNG/#136" alt=""><img src="res:/PNG/#137" alt=""><img src="res:/PNG/#132" alt=""><img src="res:/PNG/#133" alt=""></div>{{~}}';
		var l = doT.template(tpl)(data);
		lst.innerHTML = l;
	};
})();