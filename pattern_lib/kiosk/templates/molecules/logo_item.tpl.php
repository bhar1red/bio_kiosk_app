<div class="molecules__logo-item">
  <div class="card__inner <?php print empty($model['styles'])?'':implode(' ',$model['styles']);?>">
   <?php if(!empty($model['logo'])): ?>
    <div class="card__logo">
      <a href="<?php print $model['target_link']['url'];?>" aria-label="<?php print $model['target_link']['title'];?>" class="atoms__link-field chart" data-percent="100">
        <?php print TPLRender::image($model['logo']); ?>
      </a>      
    </div>
    <?php endif; ?>
    <?php if(!empty($model['target_link'])): ?>
    <div class="card__link"><?php print TPLRender::link($model['target_link']);?></div>
    <?php endif; ?>
  </div>
</div>