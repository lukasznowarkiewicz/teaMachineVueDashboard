import { createRouter, createWebHistory } from "vue-router";
import Home from "@/views/Home.vue";

export const router = createRouter({
  history: createWebHistory(),
  routes: [
    {
      path: "/",
      component: Home,
    },
    {
      path: "/tea/:slug",
      // : - parametr w http
      component: () =>
        import(/* webpackChunkName: "tea-details" */ "@/views/TeaDetails.vue"),
        // @ resolves to folder src - in vite.config.ts, just to simplife source declaration
    },
    {
      path: "/makeTea/:teaId",
      component: () => import(/* webpackChunkName: "make-tea" */ "@/views/MakeTea.vue")
    },
    {
      path: "/:pathMatch(.*)*",
      redirect: "/",
      // jak nie znajdzie, bledna sciezka (cos ala 404) ale redirect do strony głownej
    },
  ],
});
// to jest interfejs - jakie ścieki przekazujemy przez jakieś klasy