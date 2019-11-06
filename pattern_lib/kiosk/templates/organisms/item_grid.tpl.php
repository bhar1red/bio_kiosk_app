<?php $col_classes = $model['layout']; //'col-sm-3 col-xs-12'; ?>
<?php $count = count($model['items']); ?>
<div class="organisms__item-grid">
  <?php foreach($model['items'] as $item): ?>
    <div class="<?php print $col_classes;?>">
      <?php if(!empty($item['model']) && !empty($item['tpl'])): ?>
        <?php print TPLRender::component($item['model'],$item['tpl']); ?>
      <?php endif; ?>
    </div>
  <?php endforeach; ?>
</div>