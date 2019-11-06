<?php

class SplashHandler extends BaseHandler {

  /**
   * Constructor
   */
  public function __construct(AdapterTransformEvent $event) {
    $this->event = $event;
  }

  public function load() {
    $source = $this->event->getSource();
    $destination = $this->event->getDestination();
    $model = $destination->getResult();
    $config = $this->event->getConfig();
    $element_exec = new ElementExecutable();
    $model['tab'] = $element_exec->process('splash_menu', $source, $config);
    $model['main'] = $element_exec->process('splash_main', $source, $config);
    $destination->setResult($model);
  }

  public function processMenu() {
    $source = $this->event->getSource();
    $destination = $this->event->getDestination();
    $model = $destination->getResult();
    $terms = $source->rawSource();
    $model['tabs'] = $this->buildMenu($terms, 0);
    $destination->setResult($model);
  }

  public function processCarousal() {
    $source = $this->event->getSource();
    $destination = $this->event->getDestination();
    $model = $destination->getResult();
    $terms = $source->rawSource();
    $config = $this->event->getConfig();
    $items = [];
    for ($i = 0; $i < count($terms); $i++) {
      $context = ['entity_type' => 'taxonomy_term', 'pane_index' => $i];
      $item_source = new EntityModel($terms[$i], $context);
      $element_exec = new ElementExecutable();
      $element = $element_exec->process('splash_pane', $item_source, $config);
      $items[] = $element;
    }
    $model['items'] = $items;

    $destination->setResult($model);
  }

  public function processPane() {
    $source = $this->event->getSource();
    $destination = $this->event->getDestination();
    $model = $destination->getResult();
    $context = $source->getContext();
    $term = $source->rawSource();
    $model['cta_link']['url'] = base_path().drupal_lookup_path('alias','taxonomy/term/'.$term->tid); 
    $model['styles'] = [$this->skin_options[$context['pane_index']]];
    $destination->setResult($model);
  }

}
