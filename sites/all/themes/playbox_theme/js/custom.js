// We define a function that takes one parameter named $.
(function ($) {
	/*============================================
	Navigation Functions
	==============================================*/
	if ($(window).scrollTop()===0){
		$('#main-nav').removeClass('scrolled');
	}
	else{
		$('#main-nav').addClass('scrolled');
	}

	$(window).scroll(function(){
		if ($(window).scrollTop()===0){
			$('#main-nav').removeClass('scrolled');
			toggleLogo(true);
		}
		else{
			$('#main-nav').addClass('scrolled');
			toggleLogo(false);
		}
	});

	$('#site-nav').width('100px');

  /**
   * Toggle the hidden class on both logos so we show one and hide the other.
   */
  function toggleLogo(remove){
    var hidden = 'hidden';
    $('#logo-dark').toggleClass(hidden, remove);
		$('#logo-white').toggleClass(hidden, !remove);
  }
  
	/*============================================
	ScrollTo Links
	==============================================*/
	$('a.scrollto').click(function(e){
		$('html,body').scrollTo(this.hash, this.hash, {gap:{y:-50},animation:  {easing: 'easeInOutCubic', duration: 1600}});
		e.preventDefault();

		if ($('.navbar-collapse').hasClass('in')){
			$('.navbar-collapse').removeClass('in').addClass('collapse');
		}
	});

	/*============================================
	Tooltips
	==============================================*/
	$("[data-toggle='tooltip']").tooltip();

	/*============================================
	Placeholder Detection
	==============================================*/

	if (!Modernizr.input.placeholder) {
		$('#contact-form').addClass('no-placeholder');
	}

	/*============================================
	Scrolling Animations
	==============================================*/

	$('.scrollimation').waypoint(function(){
		$(this).addClass('in');
	},{offset:function(){
			var h = $(window).height();
			var elemh = $(this).outerHeight();
			if ( elemh > h*0.3){
				return h*0.7;
			}else{
				return h - elemh;
			}
		}
	});

	/*============================================
	Resize Functions
	==============================================*/
	$(window).resize(function(){
		scrollSpyRefresh();
		waypointsRefresh();
	});
	/*============================================
	Refresh scrollSpy function
	==============================================*/
	function scrollSpyRefresh(){
		setTimeout(function(){
			$('body').scrollspy('refresh');
		},1000);
	}

	/*============================================
	Refresh waypoints function
	==============================================*/
	function waypointsRefresh(){
		setTimeout(function(){
			$.waypoints('refresh');
		},1000);
	}

	/*============================================
	Handle logo swapping for large screens
	==============================================*/
  
	/*============================================
	Disco Party Time!
	==============================================*/
	$( document ).ready(function(){
		//Set default color
		var default_color = Drupal.settings.playboxadmin.default_color;
		var enabled_colors = [default_color];
		add_disco_sheet(default_color);
		
		//If disco mode is enabled, periodically swap colors
		if(Drupal.settings.playboxadmin.disco == 1){
			var colors = Drupal.settings.playboxadmin.colors;
			var random_color = '';
			var last_color = default_color;			
			
			setInterval(function(){
				//pick a random color and disable all other colors, but don't pick the same color twice
				random_color = pickRandomObjectProperty(colors);
				while(random_color == last_color){
					random_color = pickRandomObjectProperty(colors);
				}
				last_color = random_color;
				$('link.playbox-css-disco').attr('disabled', 'disabled');
				
				if($.inArray(random_color, enabled_colors) > -1){
					//If the CSS sheet is already added just enable it
					$('link.playbox-css-disco.'+random_color).removeAttr('disabled')

				}else{
					//Else add a new enabled sheet and add to color list
					enabled_colors.push(random_color);
					add_disco_sheet(random_color);
				}
			}, 1000)
		}
	});
	
	/*
	 * Used to add disco stylesheets from above "Disco Party Time!" to not duplicate code
	 */
	function add_disco_sheet(color){
		var path = Drupal.settings.playboxadmin.path;
		$('body').append('<link href="'+path+color+'.css" rel="stylesheet" class="playbox-css-disco '+color+'" />');
	}
	
	/*
	 * Picks a random value from an object
	 * http://stackoverflow.com/questions/2532218/pick-random-property-from-a-javascript-object
	 */
	function pickRandomObjectProperty(obj) {
		var result;
		var count = 0;
		for (var prop in obj)
			if (Math.random() < 1/++count)
			   result = prop;
		return result;
	}
}(jQuery));
