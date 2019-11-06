var idleTime = 0;
var isIphone = /iphone/i.test(navigator.userAgent.toLowerCase());
var isAndroid = /android/i.test(navigator.userAgent.toLowerCase());
(function ($) {
  Drupal.behaviors.kioskTimeout = {
    attach: function (context, settings) {
    	var modal_timeout = settings.kiosk_app.modal_timeout;
    	var modal_timeout_buffer = settings.kiosk_app.modal_timeout_buffer;
    	var app_timeout = settings.kiosk_app.app_timeout;
    	var app_timeout_buffer = settings.kiosk_app.app_timeout_buffer;
        var timerIncrement = function (){
          // if phone never increment or show timeout. If switches to non-phone counter continues
          if (!isIphone && !isAndroid) {idleTime = idleTime + 1;}
          if($('#qr-scanner-modal').is(':visible')){
            if (idleTime > modal_timeout) {
              $('#qr-scanner-modal .modal-dialog .modal-content').hide();
              $('#qr-scanner-modal .modal-dialog .modal-time-out').show();
              idleTime = 0;
            }
          }
          else{
            if (idleTime > app_timeout) {
            	$('#kiosk-timeout-screen').show();
                  idleTime = 0;
              }
          }
          if($('#kiosk-timeout-screen').is(':visible')){
              if (idleTime > app_timeout_buffer) {
                  window.location.href = "/kiosk/home";
                }
          }
          if($('#qr-scanner-modal .modal-dialog .modal-time-out').is(':visible')){
            if (idleTime > modal_timeout_buffer) {
              window.location.reload();
            }
          }
        }

        //Increment the idle time counter every minute.
        var idleInterval = setInterval(timerIncrement, 1000); // 1 second

        //Zero the idle timer on mouse movement.
        $(document).on('mousemove', function() {
          idleTime = 0;
        });
        $(document).on('keypress', function() {
          idleTime = 0;
        });

        $("#kiosk-timeout-continue-yes").click(function(){
        	$('#kiosk-timeout-screen').hide();
         });
         $("#kiosk-timeout-continue-no").click(function(){
        	window.location.href = "/kiosk/home";
         });


        $("#modal-timeout-continue-yes").click(function(){
           $('#qr-scanner-modal .modal-dialog .modal-content').show();
           $('#qr-scanner-modal .modal-dialog .modal-time-out').hide();
        });
        $("#modal-timeout-continue-no").click(function(){
          window.location.reload();
        });
    }
  };
})(jQuery);
