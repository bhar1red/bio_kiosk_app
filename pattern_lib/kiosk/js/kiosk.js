(function ($) {
  Drupal.behaviors.kioskApp = {
    attach: function (context, settings) {
    	var autoplayspeed = settings.kiosk_app.landingSliderAutoplaySpeed * 1000;
    	var animationspeed = settings.kiosk_app.landingSliderAnimationSpeed * 1000;
      var tabletBP = 768, kioskBP = 1080;
      var slickToggle = function(){
        var $windowWidth = $(window).width();
        var screenSize = window.screen.width;
        if ($windowWidth < tabletBP) {
          $('.pages__splash .region__main').css('padding-top',$('.pages__splash .region__top').height()+'px');
        }else{
          $('.pages__splash .region__main').css('padding-top','60px');
        }
        $('.organisms__item-carousel > .card__inner').each(function(e){
          if ($windowWidth < tabletBP) {
            if(!$(this).hasClass('flat-mode')){
              $(this).addClass('flat-mode mobile').removeClass('slide-mode wide-resolution');
              $(this).find('.slick__container').slick('unslick');
            }
          }else{
            if(!$(this).hasClass('slide-mode')){
              $(this).addClass('slide-mode wide-resolution').removeClass('flat-mode mobile');
              $(this).find('.slick__container').slick({
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
              $(this).find('.slick__prev').click(function(){
                $(this).parents('.organisms__item-carousel').find('.slick__container').slick('slickPrev');
              });
              $(this).find('.slick__next').click(function(){
                $(this).parents('.organisms__item-carousel').find('.slick__container').slick('slickNext');
              });
              $(this).find('.slick__container').on('beforeChange', function (event, slick, currentSlide, nextSlide) {
                var prevNav = $(this).siblings('.slick__prev');
                if(nextSlide==0)
                  $(prevNav).hide();
                else
                  $(prevNav).show();
                if(screenSize == kioskBP) { // only associate carousel and logo in kiosk mode
                  var activeContainer = $('.organisms__item-grid :nth-child('+nextSlide+')').find('.molecules__logo-item');
                  var activeLogo = activeContainer.find('.animation__wrapper');
                  var cardInner = activeContainer.find('.card__inner');
                  var curLogo = $('.organisms__item-grid :nth-child('+currentSlide+')')
                    .find('.molecules__logo-item').removeClass('active').find('.animation__wrapper');
                  if(activeContainer.length>0){
                    // circle animation
                    activeContainer.addClass('active');
                  }
//                  if($windowWidth == 1080){ // auto scroll only on kiosk mode 
                    if(nextSlide==0){
                      $('html,body').scrollTop(0);
                    }else{
                      var nextRow = Math.floor((nextSlide-1)/4)+1, curRow = currentSlide ? (Math.floor((currentSlide-1)/4)+1) : 1;
                      $('html,body').scrollTop(314*(nextRow-1));
                    }
//                  }
                }
              });
              Drupal.behaviors.kioskApp.isScrolling = false;
            }
          }
        });
      };
      
      slickToggle();
      
      $(window).resize(function () {
        slickToggle();
      });
      
      $( window ).scroll(function(event) {
        var screenSize = window.screen.width;
        if (screenSize == kioskBP) {  // only associate carousel and logo in kiosk mode
          $('.organisms__item-carousel > .card__inner').each(function(e){
            if($(this).hasClass('slide-mode')){
              var currentSlide = $(this).find('.slick__container').slick('slickCurrentSlide');
              var curRow = currentSlide ? (Math.floor((currentSlide-1)/4)+1) : 1;
              var targetRow = Math.floor($(window).scrollTop()/300)+1;
              if(curRow != targetRow){
                var targetSlide = (targetRow-1)*4+1;
                $(this).find('.slick__container').slick('slickGoTo', targetSlide);
              }
            }
          });
        }
      });     
      
      $('.org__home a').click(function() {
        $(this).addClass('animated pulse');
      });
      $('.card__cta-link, .card__logo, .org__mailto-bottom, .org__home, .org__mailto-top').click(function () {
        $(this).addClass('pulse animated');
        setTimeout(function () {
          $('.card__cta-link, .card__logo, .org__mailto-bottom, .org__home, .org__mailto-top').removeClass('pulse animated');
        }, 2000);
      }); 
      
      $('.molecules__contact-item .card__inner').bind('touchstart', function(){
        $(this).find('.contact__email, .contact__phone').show();
      }).bind('touchend', function(){
//        $(this).find('.contact__email, .contact__phone').hide();
      });
      
    }
  };
})(jQuery);