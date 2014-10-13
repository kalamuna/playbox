## Playbox

Playbox! is a sandbox-proving-ground for people interested in working with us here at [Kalamuna](http://www.kalamuna.com). It's a magnificent and collaborative code-garden where would-be code artists, site builder and designers alike can play around and show what they've got. It's also a place where you can ask questions, collaborate and learn. In a lot of ways it is kind of like [this](https://www.youtube.com/watch?v=8tJoIaXZ0rw). Think you've got what it takes?

## Your Mission

You've been handed a Drupal 7 project called [Megaman Robots vs US Presidents](http://playbox.kalamuna.com) which was built by another development team. It is a [Minimal Lovable Product (MLP)](http://www.slideshare.net/spookstudio/the-minimum-loveable-product-31984451). This means that it has all the core functionality it needs to deliver value but it lacks the full suite of features it needs to be face-meltingly awesome. Additionally, the budget was tight at the end of the MLP phase so the code did not go through a rigorous testing or QA process. This means that the code is rife with bugs, fast and easy code, and not tested for mobile/cross browser compatibility.

Your mission, if you choose to accept it is two fold:

**1. Help build out some of the remaining features that are [listed here](https://github.com/kalamuna/playbox/issues).**

**2. Explore the code, test the site, identify bugs, [submit those bugs or suggest improvements](https://github.com/kalamuna/playbox/issues/new) and then make them real.**

You should timebox about an **hour or two** but obviously feel free to spend as much time as you want. **Focus on the things you want to focus on**.

## Getting started

In order to get started you will want to do the following:

1. Set up your own [github.com account](https://github.com/join) if you don't already have one.
2. Set up a local development environment like [Kalabox](https://github.com/kalamuna/kalaboxv1) or [Kalastack](https://github.com/kalamuna/kalastack).
3. [Create a fork of this](https://github.com/kalamuna/playbox/fork) project.
4. [Import](https://github.com/kalamuna/kalastack/wiki/How-to-import-a-preexisting-Drupal-site-into-kalastack.) this fork into your local dev environment and set up its [files](http://files.kalamuna.com/playbox_files.tar.gz) and [database](http://files.kalamuna.com/playbox_database.sql.gz).
5. Set up your git repo for github flow. See [below](#Contributing).
6. Create a branch for the issue you are working on.
7. Commit code and push it up!

**Please refer to the Resources section below to aid in the above**

## Contributing

Before you get started you will want to clone your fork of this projet and set up the canonical upstream repo.

`From inside your webroot (generally /var/www)`

```bash
git clone git@github.com:pirog/playbox.git playbox
cd playbox
git remote add upstream https://github.com/kalamuna/playbox.git
git remote -v # this should list both an origin and upstream
```

You will want to replace git@github.com:pirog/playbox.git with your own fork. If you have already imported your site as in 4. above you can skip `git clone`.

Here is an example of a contribution workflow. You will want to read more on [git basics](http://git-scm.com/book/en/Getting-Started-Git-Basics) and [github flow](http://scottchacon.com/2011/08/31/github-flow.html) first.

You've selected issue a issue to work. The issue deals with responsive bootstrap fixes for IE6. Here is some code-fu that might happen while you contribute

```bash
git checkout master
git pull upstream master # Grab the latest code from the canonical repo
git checkout -b ie6-magix # Create a branch for your feature
```

**YOU WRITE THE CODES**

```bash
git status # List the files that have changed
git add -A # Add all files you've changed to commit
git commit -m "These are really awesome fixes that i made"
git push upstream ie6-magix # This will push your code up to `github.com/kalamuna/playbox`
```

Next Steps

1. Submit a pull request for your issue.
2. You may get requests to change your code. You can still commit code to the pull request using part 2 of the code samples above.
3. Your code gets merged in by the project maintainer.
4. The code runs through automated testing and then, if tests pass, it is deployed to http://dev-playbox.at.kalamuna.com/.

## Posting Issues

Posting issues or feature requests is fairly straight forward. Simple go to https://github.com/kalamuna/playbox/issues/new. You may want to make use of the various tags there to better explain your issue.

## FAQ

**But... I don't know how to write code?**

That's OK! In Drupal you can do a lot of stuff just by using the user interface. In fact, almost all of this site was built this way. The problem with this is that in Drupal most of this configuration is stored directly in the database and as such is difficult to put into code. Enter the [features module](https://www.drupal.org/documentation/modules/features) which allows you to export what you build in the UI into code so that you can contribute using the workflows above. Almost all the code here was exported using features and you can scope it out at `sites/all/modules/playbox_*`.

**How do i log in?**

To get into a Drupal site you usually navigate to the `/user` directory. The database posted above has an admin user. If you are using [drush](http://drush.ws/) (which comes with both Kalabox and Kalastack) this is really easy to do. SSH into the box from the dash on kalabox or run `vagrant ssh` from your kalabox directory. From there you can do the following:

```bash
cd /var/www/playbox
drush @kalastack.playbox.kala uli
```

Copy this link into the browser for a one-time login as the admin user. **Now you have all the powers!**

**I hear a lot of talk about code, files and database.. what are each?**

In Drupal your site is separated into three components:

**CODE - ** This is all the PHP/CSS/JS/HTML that comprises your application. It is usually stored in version control like `git`.
**DATABASE - ** This is a SQL file living in a MySQL database. This contains most of the configuration and content for your application.
**FILES - ** These are static assets like images, compiled CSS, videos, PDFs, etc. These usually live inside your CODE at `sites/default/files`.

## Getting help and doing your best

We recognize this may be a lot of information to learn and digest very quickly. That's OK! Feel free to ping any Kalamuna staff on any issues you may be having. For example if you @pirog on a given issue with a question i'll get an email and will respond as soon as i can. Beyond that... the most important thing you can do is just try to contribute in anyway that you can. There are no wrong or right answers to this and its not purely a test of techincal chops but effort, what you do when you don't know the answer and things like that... SO RELAX and just play around :)

## Resources

While knowledge of the below is not required and we encourage you to contribute in any way you can it may be helpful to have some understanding of the following.

*[Drupal basics](https://www.drupal.org/documentation/concepts)
*[Local Development Environments](https://www.drupal.org/setting-up-development-environment)
*[Site building and contributing code to a drupal project](https://www.drupal.org/documentation/modules/features)
*[git basics](http://git-scm.com/book/en/Getting-Started-Git-Basics)
*[Collaborating with others with github flow](http://scottchacon.com/2011/08/31/github-flow.html)
*[kalamuna](http://www.kalamuna.com)
*[kalastack](https://github.com/kalamuna/kalastack)
*[kalabox](https://github.com/kalamuna/kalaboxv1)
*[kalamuna wiki](https://kalamuna.atlassian.net/wiki/display/KALA/kalawiki)
*[drush](http://drush.ws/)

## Kalamuna

This project was sponsored by Kalamuna.com as a way to teach, train and assess aptitude in all the things.
