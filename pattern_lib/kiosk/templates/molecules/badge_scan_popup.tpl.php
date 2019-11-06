<div class="molecules__qrscanner_modal">

<div class="modal fade" id="qr-scanner-modal" role="dialog" aria-hidden="true">
    <div class="modal-dialog">
        <div class="modal-time-out" style="display:none">
            <p> Do you wish to continue?</p>
            <div class="btn-group">
              <button type="button" id="modal-timeout-continue-no" class="btn btn-primary" data-dismiss="modal">No</button>
              <button type="button" id="modal-timeout-continue-yes" class="btn btn-secondary">Yes</button>
            </div>
        </div>
        <div class="modal-content" >
            <div class="modal-header">
                 <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                    <span aria-hidden="true">&times;</span>
                </button>
            </div>
            <div class="modal-body">
                <div id="qr-scanner-content">

                    <!-- the initial scan content of modal -->
                    <div id="qr-scanner-scanning-window">
                      <video muted playsinline id="kiosk-scan-video"></video>
                        <div id="kiosk-scanning-progress" class="scan-load"></div>
                    <!--   <div class="qr-scanner-camera-select">
                        <p> Which camera would you like to use? </p>
                        <input type="radio" name="qr-scanner-radios" value="0" checked> Front </input>
                        <input type="radio" name="qr-scanner-radios" value="1"> Back  </input>
                      </div> -->
                    </div>

                    <!-- the next "page" where email is confirmed -->
                    <div id="qr-scanner-email-edit" style="display: none;">
                     <div id="qr-scanner-text">
                         <p> </p>
                     </div>    <br>
                      <div class="qr-scanner-email-field">
                        <input type="text" id="edit-kiosk-email-field" name="email_id" value="" disabled="disabled">
                         <button id="edit-kiosk-email-button" class="button--edit-kiosk-email" name="scanner-email-edit">EDIT</button>
                         <div class="error-validation" id="email-validation-error" style="display: none;">
                            <p>Please enter a valid email address.</p>
                         </div>
                          <br> <br>
                          <button id="qr-scanner-connect-with-us" class="btn btn-primary"> Connect With Us </button>
                      </div>
                      <p id="qr-scanner-look-at-other-organizations" class="qr-scanner-look-at-other-organizations">
                        <a href="<?php print $model['landing_link'];?>"> <i class="fa fa-long-arrow-left" aria-hidden="true"></i> Wait, I want to look at other organizations. </a>
                      </p>
                    </div>

                    <!-- final confirmation "page" -->
                    <div id="qr-scanner-confirmation" style="display: none;">
                        <div id="qr-scanner-text-confirmation">
                          <div class="section-main">
                            <h2>Success!</h2>
                            <p>We've sent you an email with information about <?php print $model['title'];?> as well as let them know that you are interested in connecting. You should hear from them shortly!</p>
                          </div>
                          <hr class="orange-bar"/>
                          <div class="section-related">
                            <div class="title">You may also be interested in</div>
                            <div class="organisms__item-grid">
                              <?php foreach($model['related_organizations'] as $item): ?>
                               <div class="col-sm-4 col-xs-12">
                                   <?php if(!empty($item['model']) && !empty($item['tpl'])): ?>
                                   <?php print TPLRender::component($item['model'],$item['tpl']); ?>
                                   <?php endif; ?>
                                </div>
                              <?php endforeach; ?>
                            </div>
                          </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
</div>
