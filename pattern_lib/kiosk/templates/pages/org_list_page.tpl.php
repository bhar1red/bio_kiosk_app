<?php
  $shadow_skin = 'gray-skin';
  if(!empty($model['tab']['model']['tabs'])){
    foreach($model['tab']['model']['tabs'] as $tab){
      if(!empty($tab['active'])){
        $shadow_skin = empty($tab['styles'][0]) ? 'gray-skin' : $tab['styles'][0];
        break;
      }
    }
  }
?>
<section class="pages__org-list kiosk-app">
  <div class="page__inner container-fluid">
        <?php if(!empty($model['timeout']['tpl'])): ?>
          <?php print TPLRender::component('',$model['timeout']['tpl']); ?>
        <?php endif; ?>
    <div class="region__top">
      <div class="region__menu">
        <div class="region__inner">
          <?php if(!empty($model['tab']['model']) && !empty($model['tab']['tpl'])): ?>
            <?php print TPLRender::component($model['tab']['model'],$model['tab']['tpl']); ?>
          <?php endif; ?>
        </div>
      </div>

      <div class="region__breadcrumb shadow <?php print $shadow_skin;?>">
        <div class="region__inner">
          <?php if(!empty($model['breadcrumb']['model']) && !empty($model['breadcrumb']['tpl'])): ?>
            <?php print TPLRender::component($model['breadcrumb']['model'],$model['breadcrumb']['tpl']); ?>
          <?php endif; ?>
        </div>
      </div>

      <!-- <hr class="shadow shadow~~border-bottom <?php print $shadow_skin;?>"/> -->
    </div>
    <div class="region__header">
      <div class="region__hero">
        <div class="region__inner">
          <?php if(!empty($model['hero']['model']) && !empty($model['hero']['tpl'])): ?>
            <?php print TPLRender::component($model['hero']['model'],$model['hero']['tpl']); ?>
          <?php endif; ?>
        </div>
      </div>

     <!--  <hr class="shadow shadow~~up-slate"/> -->

      <!-- <div class="region__cover"></div> -->
    </div>


    <div class="region__main">
      <div class="region__inner">
      <div class="ut-hidden-kiosk ut-hidden-tablet ut-hidden-desktop phone-carousel-replacement">
        Patient<br />
        Advocacy<br />
        Connection
      </div>
        <?php if(!empty($model['main']['model']) && !empty($model['main']['tpl'])): ?>
          <?php print TPLRender::component($model['main']['model'],$model['main']['tpl']); ?>
        <?php endif; ?>
      </div>
    </div>

  </div>
</section>
