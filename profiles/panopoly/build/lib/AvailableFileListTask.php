<?php

/**
 * @file
 * A Phing task to run Drush commands.
 */
require_once "phing/Task.php";
require_once "phing/tasks/system/condition/Condition.php";
//require_once "phing/system/io/Phingfile.php";

/**
 * AvailableFileListTask
 *
 * Like AvailableTask, but takes a filelist.
 */
class AvailableFileListTask extends Task implements Condition {

  protected $filelists = array();
  protected $property = NULL;
  protected $value = NULL;

  /**
   * Support embedded <filelist> element.
   * @return FileList
   */
  public function createFileList() {
    $filelist = new FileList();
    $this->filelists[] = $filelist;
    return $filelist;
  }

  /**
   * Set the property to set.
   *
   * @param string $str
   */
  public function setProperty($str) {
    $this->property = $str;
  }

  /**
   * Set the value to set the property to.
   *
   * @param string $str
   */
  public function setValue($str) {
    $this->value = $str;
  }

  /**
   * Get the value to set the property to.
   */
  public function getValue() {
    return ($this->value !== NULL) ? $this->value : "true";
  }

  /**
   * Evaluate the condition.
   */
  public function evaluate() {
    foreach ($this->filelists as $filelist) {
      $dir = $filelist->getDir($this->getProject());
      foreach ($filelist->getFiles($this->getProject()) as $file) {
        $file = new PhingFile($dir, $file);
        if (!$file->exists()) {
          return FALSE;
        }
      }
    }

    return TRUE;
  }

  /**
   * The main entry point method.
   */
  public function main() {
    if ($this->property === NULL) {
      throw new BuildException("property attribute is required.", $this->location);
    }

    if ($this->evaluate()) {
      $this->getProject()->setProperty($this->property, $this->getValue());
    }
  }

}

