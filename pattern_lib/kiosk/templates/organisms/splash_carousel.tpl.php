<div class="organisms__splash-carousel slick-slider">
  <div class="card__inner">
    <?php if(!empty($model['items'])): ?>
    <section class="splash__container">
      <?php foreach($model['items'] as $slider): ?>
        <div class="splash__item">
          <?php if(!empty($slider['model']) && !empty($slider['tpl'])): ?>
            <?php print TPLRender::component($slider['model'],$slider['tpl']);?>
          <?php endif; ?>
        </div>
      <?php endforeach; ?>
    </section>
    <?php endif; ?>
  </div>
</div>
