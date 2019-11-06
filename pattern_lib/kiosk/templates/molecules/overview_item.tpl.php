<div class="molecules__overview-item">
  <div class="card__inner <?php print empty($model['styles'])?'':implode(' ',$model['styles']);?>" style="background-image:url(<?php print $model['hero_bg']['src'];?>)">
    <div class="card__main">
      <?php if (!empty($model['logo'])): ?>
      <div class="card__logo">
          <?php print TPLRender::image($model['logo']); ?>
      </div>
      <?php endif; ?>
      
      <?php if(!empty($model['summary']['value'])): ?>
      <div class="card__description atom__text"><?php print $model['summary']['value'];?></div>
      <?php endif; ?>
    </div>
    <div class="card__button">
      <?php if(!empty($model['target_link'])): ?>
      <div class="card__cta-link"><?php print TPLRender::link($model['target_link']);?></div>
      <?php endif; ?>
    </div>
  </div>
</div>