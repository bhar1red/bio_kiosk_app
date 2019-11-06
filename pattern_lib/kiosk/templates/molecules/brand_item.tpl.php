<div class="molecules__brand-item">
  <div class="card__inner">
    <?php if(!empty($model['name']['value'])): ?>
    <div class="card__name atom__text"><?php print $model['name']['value'];?></div>
    <?php endif; ?>

    <?php if(!empty($model['title']['value'])): ?>
    <h1 class="card__title atom__text"><?php print $model['title']['value'];?></h1>
    <?php endif; ?>

    <?php if(!empty($model['description']['value'])): ?>
    <div class="card__description atom__text"><?php print $model['description']['value'];?></div>
    <?php endif; ?>
  </div>
</div>