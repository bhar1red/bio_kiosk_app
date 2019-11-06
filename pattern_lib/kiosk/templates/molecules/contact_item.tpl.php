<div class="molecules__contact-item">
  <div class="card__inner">
    <?php if(!empty($model['onsite']['value'])): ?>
    <div class="circle__onsite">I'm here. <br />Let's chat</div>
    <?php endif; ?>

    <?php if(!empty($model['name']['value'])): ?>
    <div class="contact__name atom__text"><?php print $model['name']['value'];?></div>
    <?php endif; ?>

    <?php if(!empty($model['email']['value'])): ?>
    <div class="contact__email atom__text"><?php print $model['email']['value'];?></div>
    <?php endif; ?>

    <?php if(!empty($model['phone']['value'])): ?>
    <div class="contact__phone atom__text"><?php print $model['phone']['value'];?></div>
    <?php endif; ?>
  </div>
</div>
