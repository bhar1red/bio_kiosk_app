<?php
  $ic_prev = [
    'icon_class' => 'fa fa-angle-left',
    'label' => '',
  ];
  $ic_next = [
    'icon_class' => 'fa fa-angle-right',
    'label' => '',
  ];
  $ic_play = [
    'icon_class' => 'fa fa-play',
    'label' => '',
  ];
  $ic_pause = [
    'icon_class' => 'fa fa-pause',
    'label' => '',
  ];
?>
<div class="organisms__item-carousel slick-slider ">
  <div class="card__inner">
    <?php if(!empty($model['slider_list'])): ?>
    <div class="slick__nav slick__prev"><div class="circle__left circle"><button class="slick__button" aria-label="Previous" type="button"><i class="font-icon fa fa-long-arrow-left" aria-hidden="true"></i></button></div></div>
    <section class="slick__container">
      <?php foreach($model['slider_list'] as $slider): ?>
        <?php if(!empty($slider['model']) && !empty($slider['tpl'])): ?>
        <div class="slick__item <?php print empty($slider['item_type'])?'':$slider['item_type'];?>">
          <?php print TPLRender::component($slider['model'],$slider['tpl']);?>
        </div>
        <?php endif; ?>
      <?php endforeach; ?>
    </section>
    <div class="slick__nav slick__next"><div class="circle__right circle"><button class="slick__button" aria-label="Next" type="button"><i class="font-icon fa fa-long-arrow-right" aria-hidden="true"></i></button></div></div>
    <?php endif; ?>
  </div>
</div>
