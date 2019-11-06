<div class="molecules__breadcrumb-bar">
  <div class="card__inner">
    <?php if(!empty($model['back_link'])): ?>
    <div class="card__back-link breadcrumb__item">
      <a href="<?php print $model['back_link']['url'];?>" aria-label="Back" class="atoms__link-field">
        <i class="font-icon fa fa-long-arrow-left" aria-hidden="true"></i>
        <?php print $model['back_link']['title'];?>
      </a>
    </div>
    <?php endif; ?>
    <?php if(!empty($model['home_link'])): ?>
    <div class="card__home-link breadcrumb__item">
      <a href="<?php print $model['home_link']['url'];?>" aria-label="Back" class="atoms__link-field">
        <?php print $model['home_link']['title'];?>
        <i class="font-icon fa fa-home" aria-hidden="true"></i>
      </a>
    </div>
    <?php endif; ?>
  </div>
</div>