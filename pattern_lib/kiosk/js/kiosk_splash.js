(function ($) {
  Drupal.behaviors.kioskSplash = {
    attach: function (context, settings) {
    	var autoplayspeed = settings.kiosk_app.splashAutoplaySpeed * 1000;
    	var animationspeed = settings.kiosk_app.splashAnimationSpeed * 1000;
      $('.organisms__splash-carousel.slick-slider .splash__container').slick({
        slidesToShow: 1,
        slidesToScroll: 1,
        autoplay: true,
        autoplaySpeed: autoplayspeed,
        prevArrow: null,
        nextArrow: null,
        speed: animationspeed,
        fade: true,
        cssEase: 'linear'      
      });
      
      $('.pages__splash .tab__item a').click(function(e){
        e.preventDefault();     
        $(this).parents('.tab__container').find('.active').removeClass('active');
        $(this).parents('.tab__item').addClass('active');
        var index = $(this).parents('.tab__item').index();
        $('.organisms__splash-carousel.slick-slider .splash__container').slick('slickGoTo', index);
        return false;
      });
      
      $('.organisms__splash-carousel.slick-slider .splash__container').on('beforeChange', function (event, slick, currentSlide, nextSlide) {
        var tabItems = $(this).parents('.pages__splash').find('.tab__item');
        tabItems.eq(currentSlide).removeClass('active');
        tabItems.eq(nextSlide).addClass('active');
      });

      $(window).resize(function () {
        var activeTab = $('.molecules__tab-menu .tab__item.active');
        var width = $(activeTab).width();
        $('.molecules__tab-menu .tab__item .arrow-down').css('border-left-width',width/2+'px').css('border-right-width',width/2+'px');
      });
    }
  };
})(jQuery);