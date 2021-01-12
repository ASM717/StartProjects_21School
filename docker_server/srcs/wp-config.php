<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'database_server' );

/** MySQL database username */
define( 'DB_USER', 'amuriel' );

/** MySQL database password */
define( 'DB_PASSWORD', 'amuriel21' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '1#FC+k~{lqTpkBbFq?|QOV9_+]E>,CUd$wY|bw^2.LH~ARf-3Qi)Da((4uZZ]hL[');
define('SECURE_AUTH_KEY',  '9}mcsR~m45g{LSDcJWa4mmhV-[[Z@j&=qL+8+>VE+s|zE}(P-<_Jk nIAb*%Zlzs');
define('LOGGED_IN_KEY',    'y#u$jA?_:+ROaRwH=KJLD[;q(H3UKJUznT?Gi!7U=14^jvQ!Z]qU-D`>e/b&qfHK');
define('NONCE_KEY',        'lvFax0Y2aa`G.;H#GtZ2u3(I^DyMLA_`&aK;-:uBV[``v{6#}0ct{A@dpKuH#eoI');
define('AUTH_SALT',        'xh~qiC@~Z+OUAH1A63aJIo7/7sC|sdcMbTRY+fmg!Y8@;$1Z7=.OK-l9zUW-)::Q');
define('SECURE_AUTH_SALT', 'K+4^5dPLx#nc}*I).}czh?-pc)%J9[n}a,H^{IRB%1va{#2}b*~OlCar69Y+o3,r');
define('LOGGED_IN_SALT',   '1p+Tf43o0@8+T5L-B+eLX_5gf{iI>4A~]l7FgD6g>}_c$%FabXL!-cH{C+qr=B~m');
define('NONCE_SALT',       '~P-Ldfbf9-D+.{r1=CpkjaY$jN*~.bm&sn&n.-8|X9xX-c;yC sA$`Rh==),u-vs');
/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';

