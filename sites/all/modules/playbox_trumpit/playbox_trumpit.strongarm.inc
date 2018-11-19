<?php
/**
 * @file
 * playbox_trumpit.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function playbox_trumpit_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'playbox_trumpit_phrases';
  $strongarm->value = '“I’m the worst thing that’s ever happened to ISIS.” 
“Donald J. Trump is calling for a total and complete shutdown of Muslims entering the United States.” 
“Did you read about Starbucks? No more \'Merry Christmas\' at Starbucks. No more. Maybe we should boycott Starbucks." 
“Sorry, there is no STAR on the stage tonight!” 
“Look at that face! Would anyone vote for that? Can you imagine that, the face of our next president?" 
“We have to have a wall. We have to have a border. And in that wall we’re going to have a big fat door where people can come into the country, but they have to come in legally.” 
“I’m owned by the people! I mean, I’m telling you, I’m no angel, but I’m gonna do right by them!” 
“I think apologizing’s a great thing, but you have to be wrong. I will absolutely apologize, sometime in the hopefully distant future, if I’m ever wrong.” 
“When these people walk in the room, they don’t say, ‘Oh, hello! How’s the weather? It’s so beautiful outside. Isn’t it lovely? How are the Yankees doing? Oh they’re doing wonderful. Great.’ [Asians] say, ‘We want deal!’” 
“You haven’t been called, go back to Univision.” 
“Heidi Klum. Sadly, she\'s no longer a 10." 
“You could see there was blood coming out of her eyes. Blood coming out of her… wherever.” 
“He’s not a war hero. He’s a war hero because he was captured. I like people who weren’t captured.” 
“No more massive injections. Tiny children are not horses—one vaccine at a time, over time.”
“When Mexico sends its people, they’re not sending the best. They’re sending people that have lots of problems and they’re bringing those problems. They’re bringing drugs, they’re bringing crime. They’re rapists and some, I assume, are good people, but I speak to border guards and they’re telling us what we’re getting.” 
“NBC News just called it ‘The Great Freeze’ — coldest weather in years. Is our country still spending money on the GLOBAL WARMING HOAX?”
“I have a great relationship with the blacks. I’ve always had a great relationship with the blacks.”
“Do you know that Hillary Clinton was a birther? She wanted those records and fought like hell. People forgot. Did you know John McCain was a birther? Wanted those records? They couldn’t get the records. Hillary failed. John McCain failed. Trump was able to get him to give something — I don’t know what the hell it was — but it doesn’t matter.”
“Rosie O’Donnell’s disgusting both inside and out. You take a look at her, she’s a slob. She talks like a truck driver, she doesn’t have her facts, she’ll say anything that comes to her mind. Her show failed when it was a talk show, the ratings went very, very, very low and very bad, and she got essentially thrown off television. I mean she’s basically a disaster.”
“It’s like in golf. A lot of people — I don’t want this to sound trivial — but a lot of people are switching to these really long putters, very unattractive. It’s weird. You see these great players with these really long putters, because they can’t sink three-footers anymore. And, I hate it. I am a traditionalist. I have so many fabulous friends who happen to be gay, but I am a traditionalist.”
“I’ve said if Ivanka weren’t my daughter, perhaps I’d be dating her.”
“All of the women on The Apprentice flirted with me — consciously or unconsciously. That’s to be expected.” 
“The line of ‘Make America great again,’ the phrase, that was mine, I came up with it about a year ago, and I kept using it, and everybody’s using it, they are all loving it. I don’t know I guess I should copyright it, maybe I have copyrighted it.”
';
  $export['playbox_trumpit_phrases'] = $strongarm;

  return $export;
}
