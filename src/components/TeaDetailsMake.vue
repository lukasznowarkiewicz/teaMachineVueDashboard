<template>
    <button @click="redirectToMakeTea()">Back</button>
</template>
<script setup lang="ts">
import { useRouter } from "vue-router";

const router = useRouter();

const redirectToMakeTea = () => {
  router.push("/MakeTea");
};
</script>