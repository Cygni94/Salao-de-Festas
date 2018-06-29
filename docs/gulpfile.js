// Para rodar o browsersync e o sass, utilize npm run gulp server
// Para gerar a versão dist, utilize npm run gulp

// INSTALE O GULP-SPRITESMITH: https://github.com/twolfson/gulp.spritesmith

var gulp = require("gulp"),
    browserSync = require("browser-sync").create(),
    sass = require("gulp-sass");
wait = require("gulp-wait");

// Static Server + watching scss/html files
gulp.task("serve", ["sass"], function() {
    browserSync.init({
        server: "./",
    });

    gulp.watch("./assets/sass/**/*", ["sass"]);
    gulp.watch("./*.html").on("change", browserSync.reload);
});

// Compile sass into CSS & auto-inject into browsers
gulp.task("sass", function() {
    return gulp
        .src("./assets/sass/*.scss")
        .pipe(wait(500))
        .pipe(sass())
        .pipe(gulp.dest("./assets/css"))
        .pipe(browserSync.stream());
});

gulp.task("default", ["serve"]);
