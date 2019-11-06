(function ($) {
  Drupal.behaviors.kioskScan = {
    attach: function (context, settings) {
        var timerEditEmail;
    	window.node_id = settings.kiosk_app.node_id;
    	window.title = settings.kiosk_app.title;
    	window.first_name = "";
    	window.last_name = "";
    	$('#kisosk-scan-me-button').click(function(){
        $("#kiosk-scanning-progress").attr("class", "scan-load");
        let scanner = new Instascan.Scanner({ video: document.getElementById('kiosk-scan-video'),  mirror: false });
        scanner.addListener('scan', function (content) {
        	//$("#kiosk-scanning-progress").text('QR Code detected. Retrieving email id');
        	var email_id="";
        	$.ajax({
            url: '/api/kiosk-app-get-email.json?barcode='+ encodeURIComponent( content),
            success: function(data){
              email_id = data['Email'];
              first_name = data['FirstName'];
              last_name = data['LastName'];
              window.email_id = email_id;
              window.first_name = first_name;
              window.last_name = last_name;
              window.user_data = data;
              //("#kiosk-scanning-progress").text('Email Retrieved! ');
              $("#kiosk-scanning-progress").attr("class", "scan-complete");
              timerEditEmail = setTimeout(function(){
                $("#qr-scanner-scanning-window").hide();
                $('#qr-scanner-email-edit').show();
                if(first_name != null){
                	$('#qr-scanner-text').html('<div class="qr-scanner-text"><h3> Hi ' + first_name + '</h3> <p> Did we get your email correct? </p></div>');
                }
                else{
                	$('#qr-scanner-text').html('<p class="qr-scanner-text"> We have trouble retrieving your info. <br/> Please enter your email. </p>');
                }
                if(!($('.input1').val())){
                  $('#edit-kiosk-email-field').val(window.email_id);
                }
                scanner.stop();
              }, 3000);
              idleTime = 0;
            },
      		error: function(data){
              idleTime = 0;
              $("#qr-scanner-scanning-window").hide();
              $('#qr-scanner-email-edit').show();
              $('#qr-scanner-text').html(' <p class="qr-scanner-text"> We have trouble retrieving your info. <br/> Please enter your email. </p>');
              scanner.stop();

		   }
		      });
        });


        startCamera(0);

        function startCamera(camera_val){
            Instascan.Camera.getCameras().then(function (cameras) {
                if (cameras.length > 0) {
              	  scanner.start(cameras[camera_val]);
                  $("#kiosk-scanning-progress").attr("class", "scan-progress");
                  setTimeout(function(){
                	  $("#kiosk-scanning-progress").attr("class", "");
                  }, 2000);
                } else {
                  console.error('No cameras found.');
                }
              }).catch(function (e) {
                console.error(e);
              });
        }

        $("input[name=qr-scanner-radios]").change(function(){
        	var radioValue = $("input[name=qr-scanner-radios]:checked").val();
        	scanner.stop();
            startCamera(radioValue);

        })

      });

      $('#qr-scanner-content').on('click', '#edit-kiosk-email-button', function () {
        if($('#edit-kiosk-email-button').text() == "EDIT"){
          $("#edit-kiosk-email-field").prop('disabled', false);
          $('#edit-kiosk-email-field').focus();
          $('#edit-kiosk-email-button').text("CONFIRM");
        }
        else{
         var new_email = $('#edit-kiosk-email-field').val();
       	  if ( !validateEmail(new_email) ){
            	$('#email-validation-error').show();
            }
      	  if( validateEmail(new_email) ){
      		  $('#email-validation-error').hide();
              $("#edit-kiosk-email-field").prop('disabled', true);
              $('#edit-kiosk-email-button').text("EDIT");
      	  }
        }

      });

      function validateEmail($email) {
    	  if($email == "" ){
    		  return false;
    	  }
    	  var emailReg = /^([\w-\.]+@([\w-]+\.)+[\w-]{2,4})?$/;
    	  return emailReg.test( $email );
    	}

      $("#edit-kiosk-email-field").focusout(function(){
    	  console.log("focussed out ");
    	  var new_email = $('#edit-kiosk-email-field').val();
    	  if ( !validateEmail(new_email) ){
          	$('#email-validation-error').show();
          }
    	  if( validateEmail(new_email) ){
    		  $('#email-validation-error').hide();
    	  }
      });

      $('#qr-scanner-connect-with-us').click(function() {
        var new_email = $('#edit-kiosk-email-field').val();
        if( validateEmail(new_email)) {
            clearTimeout(timerEditEmail);
  		    $('#email-validation-error').hide();
            $.ajax({
              method: "POST",
              url: '/api/kiosk-app-email-submit.json',
              dataType: "json",
              contentType: "application/json",
              data: JSON.stringify({
                node_id: window.node_id,
                email: new_email,
                name: window.first_name,
                user_data: window.user_data
              }),
              success: function(data){
                $("#qr-scanner-email-edit").hide();
                $('#qr-scanner-confirmation').show();
                idleTime = 0;
              },
              error: function(data){
                idleTime = 0;
                $("#qr-scanner-email-edit").hide();
                $("#qr-scanner-text-confirmation").html(
                		"<div class='qr-scanner-failure' id='qr-scanner-failure'>" +
                		"<i class='fa fa-exclamation-circle' aria-hidden='true'></i>" +
                		"<h2> Error! </h2>" +
                		"<p> We have trouble submitting your email.</p>" +
                		"<p>Please try again. </p>" +
                		"</div>"

                		);
                $('#qr-scanner-confirmation').show();
              }
            });
        }
        else if ( !validateEmail(new_email) ){
        	$('#email-validation-error').show();
        }
      });

      $('#qr-scanner-modal').on('hidden.bs.modal', function () {
        location.reload();
      });
    }
  };
})(jQuery);
