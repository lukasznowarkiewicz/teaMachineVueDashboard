<template>
<!-- :nazwa deklaruje properties przekazywane z rodzica na dziecko (pod VUE)-->
  <button style="margin-top: -10em; margin-left: 70%; position: absolute"><div class="icon">
    <div class="cogs">
      <div class="cog"></div>
      <div class="cog"></div>
      <div class="cog"></div>
      <div class="cog"></div>
    </div>
    <div class="wheel"></div>
  </div></button>
  <TeaPreview v-for="tea in teaData" :key="tea.id" :tea="tea" @click="redirectToTeaDetails(tea.slug)" />

</template>

<script setup lang="ts">
import { ref } from 'vue';
import { useRouter } from 'vue-router';
import teaJson from '@/assets/tea.json'
import TeaPreview from '@/components/TeaPreview.vue';

const router = useRouter();

const redirectToTeaDetails = (teaSlug: string) => {
  router.push(`/tea/${teaSlug}`);
  // router - metoda VUE - router (useRouter)
};

const teaData = ref(teaJson);
</script>

<!-- component lifecycle VUE - poczytac  -->

<style>
* {
  margin: 0;
  padding: 0;
}

.icon {
  position: relative;
  height: 80px;
  width: 80px;
}

.wheel {
  position: absolute;
  left: 0;
  right: 0;
  top: 0;
  bottom: 0;
  margin: auto;
  width: 16px;
  height: 16px;
  background: rgb(0, 0, 0);
  border-radius: 50%;
  border: solid 12px brown;
}

.cog {
  position: absolute;
  width: 14px;
  height: 60px;
  border-radius: 3px;
  background: brown;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  margin: auto;
}

.cog:nth-child(2) {
  transform: rotate(45deg);
}

.cog:nth-child(3) {
  transform: rotate(90deg)
}

.cog:nth-child(4) {
  transform: rotate(135deg)
}


</style>