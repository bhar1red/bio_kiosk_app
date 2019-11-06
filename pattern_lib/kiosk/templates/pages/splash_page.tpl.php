<section class="pages__splash kiosk-app">
  <div class="page__inner container-fluid">
    <div class="region__top">
      <div class="region__menu">
        <div class="region__inner">
          <?php if(!empty($model['tab']['model']) && !empty($model['tab']['tpl'])): ?>
            <?php print TPLRender::component($model['tab']['model'],$model['tab']['tpl']); ?>
          <?php endif; ?>
        </div>
      </div>
    </div>
    <div class="region__main">
      <div class="region__inner">
        <?php if(!empty($model['main']['model']) && !empty($model['main']['tpl'])): ?>
          <?php print TPLRender::component($model['main']['model'],$model['main']['tpl']); ?>
        <?php endif; ?>
      </div>
    </div>
  </div>
</section>

