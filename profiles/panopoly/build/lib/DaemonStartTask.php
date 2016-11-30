<?php

/**
 * @file
 * A Phing task to run start a daemon.
 */
require_once "phing/Task.php";

/**
 * DaemonStartTask
 */
class DaemonStartTask extends Task {

  protected $command = NULL;
  protected $dir = NULL;
  protected $pid = NULL;

  /**
   * Set the command to run.
   *
   * @param string $str
   */
  public function setCommand($str) {
    $this->command = $str;
  }

  /**
   * Set the dir to run the command in.
   *
   * @param PhingFile $dir
   */
  public function setDir(PhingFile $dir) {
    $this->dir = $dir;
  }

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
    if ($this->command === NULL) {
      throw new BuildException("property command is required.", $this->location);
    }
    if ($this->pid === NULL) {
      throw new BuildException("property pid is required.", $this->location);
    }

    // Switch to the requested directory.
    if ($this->dir !== NULL) {
      $this->currdir = getcwd();
      @chdir($this->dir->getPath());
    }

    // Execute the command.
    $output = array();
    $return = NULL;
    $command = $this->command . " >/dev/null 2>&1 & echo $!";
    exec($command, $output, $return);

    // Switch back to previous directory.
    if (!empty($this->currdir)) {
      @chdir($this->currdir);
    }

    // Check that it worked.
    if ($return != 0) {
      throw new BuildException("{$this->command} failed to start with exit code $return");
    }

    // Declare success!
    $pid = trim($output[0]);
    $this->log("{$this->command} started with PID $pid");

    // Write to the PID file.
    $pid_file = fopen($this->pid->getPath(), 'wt');
    fwrite($pid_file, $pid);
    fclose($pid_file);
  }
}

