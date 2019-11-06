<?php
$ic_notes = [
  'icon_class' => 'fa fa-handshake-o',
  'label' => $model['contact']['notes'],
];

?>
<section class="pages__org-detail kiosk-app">
  <div class="page__inner container-fluid <?php print empty($model['styles']) ? '' : implode(' ', $model['styles']); ?>">

    <div class="region__top">
      <div class="region__menu">
        <div class="region__inner">
          <?php if (!empty($model['tab']['model']) && !empty($model['tab']['tpl'])): ?>
            <?php print TPLRender::component($model['tab']['model'], $model['tab']['tpl']); ?>
          <?php endif; ?>
        </div>
      </div>

      <div class="region__breadcrumb shadow <?php print 'gray-skin';?>">
        <div class="region__inner">
          <?php if (!empty($model['breadcrumb']['model']) && !empty($model['breadcrumb']['tpl'])): ?>
            <?php print TPLRender::component($model['breadcrumb']['model'], $model['breadcrumb']['tpl']); ?>
          <?php endif; ?>
        </div>
      </div>

    </div>
    <div class="region__header">
      <div class="region__hero">
        <div class="region__inner" style="background-image:url(<?php print $model['hero_bg']['src'];?>)">
          <div class="org__overview">
            <?php if (!empty($model['logo'])): ?>
              <div class="org__icon">
                <?php print TPLRender::image($model['logo']); ?>
              </div>
            <?php endif; ?>
            <?php if (!empty($model['summary']['value'])): ?>
              <div class="org__summary atom__text">
                <?php print $model['summary']['value']; ?>
              </div>
            <?php endif; ?>
          </div>
        </div>
      </div>
      <?php $submit_mode = $model['submit_mode']; ?>

      <!-- top scan / email button -->
      <?php if (!empty($model['cta_label'])): ?>
      <div class="region__button <?php if ($submit_mode == 1){ print 'ut-hidden-phone'; }?>">
        <div class="region__inner">
          <?php if ($submit_mode == 1): ?>
            <div class="card__cta-link scan-badge">
              <a id="kisosk-scan-me-button" class="button button--scan button--scan-top" href="#" data-toggle="modal" data-target="#qr-scanner-modal">
                  <?php print $model['cta_label']; ?> <i class="fa fa-camera" aria-hidden="true"></i>
              </a>
            </div>
          <?php elseif ($submit_mode == 0): ?>
            <div class="card__cta-link scan-badge">
              <a id="kisosk-email-me-button" class="button button--scan button--scan-top button--email" href="#" data-toggle="modal" data-target="#qr-scanner-modal">
                  Email Me <i class="fa fa-envelope-o" aria-hidden="true"></i>
              </a>
            </div>
          <?php endif ?>
        </div>
      </div>
      <?php endif; ?>
    </div>

    <div class="region__main">
      <div class="region__inner">
        <?php if (!empty($model['description']['value'])): ?>
          <div class="org__description">
            <h2 class="atoms__label">
              <?php print $model['description']['label']; ?>
            </h2>
            <div class="atoms__text">
              <?php print $model['description']['value']; ?>
            </div>
          </div>

      <!--  bottom scan / email button - hidden on kiosk & desktop  -->
      <?php if (!empty($model['cta_label'])): ?>
      <div class="region__button ut-hidden-kiosk ut-hidden-desktop <?php if ($submit_mode == 1){ print 'ut-hidden-phone'; }?>">
        <div class="region__inner">
          <?php if ($submit_mode == 1): ?>
            <div class="card__cta-link scan-badge">
              <a id="kisosk-scan-me-button" class="button button--scan button--scan-bottom" href="#" data-toggle="modal" data-target="#qr-scanner-modal">
                  <?php print $model['cta_label']; ?> <i class="fa fa-camera" aria-hidden="true"></i>
              </a>
            </div>
          <?php elseif ($submit_mode == 0): ?>
            <div class="card__cta-link scan-badge">
              <a id="kisosk-email-me-button"  class="button button--scan button--scan-bottom button--email" href="#" data-toggle="modal" data-target="#qr-scanner-modal">
                  Email Me <i class="fa fa-envelope-o" aria-hidden="true"></i>
              </a>
            </div>
          <?php endif ?>
        </div>
      </div>
      <?php endif; ?>

        <?php endif; ?>
        <?php if (!empty($model['contact']['list']['model']['items'])): ?>
          <div class="org__contact">
            <h2 class="atoms__label">
              <?php print $model['contact']['label']; ?>
            </h2>
            <?php if (!empty($model['contact']['list']['model']) && !empty($model['contact']['list']['tpl'])): ?>
              <?php print TPLRender::component($model['contact']['list']['model'], $model['contact']['list']['tpl']); ?>
            <?php endif; ?>
          </div>
        <?php endif; ?>
      </div>
    </div>

    <div class="region__popup">
   <!--  timeout popup  -->
     <?php if(!empty($model['timeout']['tpl'])): ?>
        <?php print TPLRender::component('',$model['timeout']['tpl']); ?>
      <?php endif; ?>

     <!-- badge scanner popup -->
    <?php $submit_mode = $model['submit_mode']; ?>
    <?php if ($submit_mode == 1): ?>
      <div class="scan-container badge-scanner">
        <?php if (!empty($model['badge_scan_popup']['model']) && !empty($model['badge_scan_popup']['tpl'])): ?>
          <?php print TPLRender::component($model['badge_scan_popup']['model'], $model['badge_scan_popup']['tpl']); ?>
        <?php endif; ?>
      </div>
    <?php elseif ($submit_mode == 0): ?>
      <?php if (!empty($model['mailto']['title'])): ?>
      <div class="scan-container email-scanner">
        <?php if (!empty($model['email_submit_popup']['model']) && !empty($model['email_submit_popup']['tpl'])): ?>
          <?php print TPLRender::component($model['email_submit_popup']['model'], $model['email_submit_popup']['tpl']); ?>
        <?php endif; ?>
      </div>
      <?php endif; ?>
    <?php endif ?>
    </div>

  </div>
</section>
