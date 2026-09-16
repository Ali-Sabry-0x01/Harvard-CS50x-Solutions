-- Users Table
CREATE TABLE `users` (
    `id` INT UNSIGNED AUTO_INCREMENT,
    `first_name` VARCHAR(64) NOT NULL,
    `last_name` VARCHAR(64) NOT NULL,
    `username` VARCHAR(64) NOT NULL UNIQUE,
    `password` CHAR(128) NOT NULL,
    PRIMARY KEY (`id`)
);

-- Schools Table
CREATE TABLE `schools` (
    `id` INT UNSIGNED AUTO_INCREMENT,
    `name` VARCHAR(128) NOT NULL,
    `type` ENUM('Primary', 'Secondary', 'Higher Education') NOT NULL,
    `location` VARCHAR(128) NOT NULL,
    `year_founded` YEAR NOT NULL,
    PRIMARY KEY (`id`)
);

-- Companies Table
CREATE TABLE `companies` (
    `id` INT UNSIGNED AUTO_INCREMENT,
    `name` VARCHAR(128) NOT NULL,
    `industry` ENUM('Technology', 'Education', 'Business') NOT NULL,
    `location` VARCHAR(128) NOT NULL,
    PRIMARY KEY (`id`)
);

-- Connections with People (Users following/connecting with other users)
CREATE TABLE `user_connections` (
    `user_a_id` INT UNSIGNED NOT NULL,
    `user_b_id` INT UNSIGNED NOT NULL,
    PRIMARY KEY (`user_a_id`, `user_b_id`),
    FOREIGN KEY (`user_a_id`) REFERENCES `users`(`id`),
    FOREIGN KEY (`user_b_id`) REFERENCES `users`(`id`)
);

-- Connections with Schools (Alumni & Education)
CREATE TABLE `user_schools` (
    `user_id` INT UNSIGNED NOT NULL,
    `school_id` INT UNSIGNED NOT NULL,
    `start_date` DATE NOT NULL,
    `end_date` DATE,
    `degree_type` VARCHAR(32) NOT NULL,
    PRIMARY KEY (`user_id`, `school_id`, `degree_type`),
    FOREIGN KEY (`user_id`) REFERENCES `users`(`id`),
    FOREIGN KEY (`school_id`) REFERENCES `schools`(`id`)
);

-- Connections with Companies (Employment History)
CREATE TABLE `user_companies` (
    `user_id` INT UNSIGNED NOT NULL,
    `company_id` INT UNSIGNED NOT NULL,
    `start_date` DATE NOT NULL,
    `end_date` DATE,
    `title` VARCHAR(64) NOT NULL,
    PRIMARY KEY (`user_id`, `company_id`, `title`),
    FOREIGN KEY (`user_id`) REFERENCES `users`(`id`),
    FOREIGN KEY (`company_id`) REFERENCES `companies`(`id`)
);
