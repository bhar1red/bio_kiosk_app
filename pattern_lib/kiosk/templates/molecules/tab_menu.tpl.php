<div class="molecules__tab-menu">
  <div class="card__inner">
    <?php if(!empty($model['tabs'])): ?>
    <section class="tab__container row">
      <?php $count = min(4,count($model['tabs'])); ?>
      <?php $cell_class = 'col-sm-'.(12/$count); ?>
      <?php foreach($model['tabs'] as $tab): ?>
        <div class="tab__item <?php print $cell_class;?> <?php print empty($tab['styles'])?'':implode(' ',$tab['styles']);?> <?php print empty($tab['active'])?'':'active';?>">
          <?php if(!empty($tab['link'])): ?>
          <div class="tab__link"><?php print TPLRender::link($tab['link']);?></div>
          <?php endif; ?>
          <div class="arrow-down"></div>
        </div>
      <?php endforeach; ?>
    </section>
    <?php endif; ?>
  </div>
</div>
