<div class="molecules__splash-pane"> 
  
  <?php if(!empty($model['video'])) {?>
   <video class="background__video" autoplay muted loop>
		<source src="<?php print $model['video']?>" type="video/mp4">
	</video>
	<div
		class="card__inner video-bg <?php print empty($model['styles'])?'':implode(' ',$model['styles']);?>">

  <?php }else { ?>
  <div class="card__inner image-bg <?php print empty($model['styles'])?'':implode(' ',$model['styles']);?>"
       style="background-image:url(<?php print $model['image']['src'];?>)">

  <?php } ?>

    <div class="card__main">
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

			<div class="card__button">
      <?php if(!empty($model['cta_link'])): ?>
      <div class="card__cta-link"><?php print TPLRender::link($model['cta_link']);?></div>
      <?php endif; ?>
    </div>
		</div>
	</div>