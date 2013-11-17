monkey-migrate
==============

This repository holds all the code required to recreate the Drupal migrate demonstrations given in the talk "Get Your Bits In", by Elliot Ward.

The talk serves as an introduction to migrating content to Drupal using the migrate module and was initially given at DrupalCampNW 2012 in Manchester. The video from that version of the talk is available at http://vimeo.com/54448150, and the latest version of the slides are available at http://prezi.com/9i5xka5asfc3/get-your-bits-in-v2/

There are two modules in this repository:

* my_migrate
* node_types

To recreate the demos in the talk, create two Drupal 7 sites on the same server* to act as source and destination. Install node_types and its dependencies to both sites, and my_migrate and its dependencies to the destination site only. 

Edit the settings.php for the destination site to add the source system to the $databases array - it should look something like this:

$databases = array(
  'default' => array(
    'default' => array(
      'database' => 'dest_local',
      'username' => 'dest_local',
      'password' => 'dest_local',
      'host' => 'localhost',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => false,
    ),
  ),
  'source_db' => array(
    'default' => array(
      'database' => 'source_local',
      'username' => 'source_local',
      'password' => 'source_local',
      'host' => 'localhost',
      'port' => '',
      'driver' => 'mysql',
      'prefix' => false,
    ),
  )
);

It must be named source_db to match the queries defined in the Migration subclasses in my_migrate.

You should now be able to run the first migration in the talk.

The second and third migrations need the comments 

/* restore this section for the second migration

and 

/* restore this section for the third migration

to be closed at the end of the line to uncomment the additional mappings.





* they don't have to be on the same server really, but the destination site needs to be able to read the file system and database of the source system so having them on the same server is the simplest way to do this.


