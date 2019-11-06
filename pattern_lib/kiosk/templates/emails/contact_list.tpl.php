<?php if(!empty($model['items'])) :?>
<table class="contacts-table">
  <tbody>
	<tr>
    <?php foreach($model['items'] as $item) :?>
      <?php if(!empty($item['model']) && !empty($item['tpl'])): ?>
        <?php print TPLRender::component($item['model'],$item['tpl']);?>
      <?php endif; ?>
    <?php endforeach; ?>
   </tr>
  </tbody>
</table>
<?php endif; ?>
