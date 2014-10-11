// This stuff depends on waypoint and easy pie chart
(function ($) {

  /*============================================
  Skills Functions
  ==============================================*/

  var color = $('.jumbotron').css('backgroundColor');

  $('.skills').waypoint(function(){
    console.log('sup');
    $('.chart').each(function(){
    $(this).easyPieChart({
        size:140,
        animate: 2000,
        lineCap:'butt',
        scaleColor: false,
        barColor: color,
        trackColor: 'transparent',
        lineWidth: 10
      });
    });
  },{offset:'80%'});

}(jQuery));
