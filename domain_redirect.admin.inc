<?php


/**
 * FormsAPI for configuring the domain redirect module.
 */
function domain_redirect_settings() {
  $form['domain_redirect_access'] = array(
    '#title' => t("Redirect on access denied"),
    '#default_value' => variable_get('domain_redirect_access', FALSE),
    '#type' => 'checkbox',
  );
  
  $form['domain_redirect_sitesall'] = array(
    '#title' => t("Don't redirect for shared node"),
    '#default_value' => variable_get('domain_redirect_sitesall', TRUE),
    '#type' => 'checkbox',
  );
  /*
  $form['domain_redirect_message'] = array(
    '#title' => t("Redirection Message"),
    '#type' => 'textarea',
    '#default_value' => variable_get('domain_redirect_message', ''),
  );
  */  
  
  $form['domain_redirect_types'] = array(
    '#title' => t("Node type settings"),
    '#type' => 'fieldset',
  );
  /* Use this format so also can be added to node type forms */
  foreach (node_get_types() as $type => $data) {
    $form['domain_redirect_types']['domain_redirect_type_' . $type] = array(
      '#title' => t("Allow redirection of @type", array('@type'=> $data->name)),
      '#default_value' => variable_get('domain_redirect_type_' . $type, TRUE),
      '#type' => 'checkbox',
    );   
  }
  return system_settings_form($form);
}
