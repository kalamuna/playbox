<?php

/**
 * @file
 * A Phing task to run stop a daemon.
 */
require_once "phing/Task.php";

/**
 * DaemonStopTask
 */
class DaemonStopTask extends Task {

  protected $pid = NULL;

  /**
   * Set the pid file to store the pid in.
   *
   * @param PhingFile $dir
   */
  public function setPid(PhingFile $file) {
    $this->pid = $file;
  }

  /**
   * The main entry point method.
   */
  public function main() {
    if ($this->pid === NULL) {
      throw new BuildException("property pid is required.", $this->location);
    }

    $pid = trim($this->pid->contents());
    if (posix_kill($pid, SIGKILL)) {
      $this->log("Killed process with PID $pid");
      $this->pid->delete();
    }
    else {
      $this->log("Unable to kill process with PID $pid");
    }
  }
}

